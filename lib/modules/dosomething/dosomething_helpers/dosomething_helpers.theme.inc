<?php

/**
 * Implements hook_theme_registry_alter()
 *
 * Modules registered in dosomething_helpers_modules will 
 * have their paths added to the theme registry so that they
 * can store reference entity type templates within the module.
**/
function dosomething_helpers_theme_registry_alter(&$theme_registry) {
  $modules = variable_get('dosomething_helpers_modules', array());
  if (!empty($modules)) {
    foreach ($modules as $module) {
      $mod_path = drupal_get_path('module', 'dosomething_' . $module);
      $theme_registry_copy = $theme_registry;
      _theme_process_registry($theme_registry_copy, 'phptemplate', 'theme_engine', 'paraneue_dosomething', $mod_path);
      $theme_registry += array_diff_key($theme_registry_copy, $theme_registry);
      $hooks = array('node');
      foreach ($hooks as $h) {
        _dosomething_helpers_insert_after_first_element($theme_registry[$h]['theme paths'], $mod_path);
      }
    }
  }
}

/**
 * Helper function for re-ordering arrays (needed by theme_registry_alter)
*/
function _dosomething_helpers_insert_after_first_element(&$a, $element) {
  if (is_array($a)) {
    $first_element = array_shift($a);
    array_unshift($a, $first_element, $element);
  }
  else {
    $a = $element;
  }
}

/**
 * Implements hook_theme().
 */
function dosomething_helpers_theme($existing, $type, $theme, $path) {
  return array(
    'dosomething_video_embed' => array(
      'variables' => array(
        'field' => NULL,
        'height' => 315,
        'width' => 560,
      ),
    ),
    'modal_links' => array(
      'variables' => array(
        'modals' => NULL,
      ),
      'template' => 'modal-links',
    ),
  );
}

/**
 * Theme callback for dosomething_video_embed.
 */
function theme_dosomething_video_embed($variables) {
  $output = '<iframe';
  $output .= " width=\"{$variables['width']}\"";
  $output .= " height=\"{$variables['height']}\"";
  if ($variables['field']->field_provider['und'][0]['value'] == 'youtube') {
    $output .= ' src="//www.' . $variables['field']->field_provider['und'][0]['value'] . '.com/embed/' . $variables['field']->field_video_id['und'][0]['value'] . '?wmode=transparent&hd=1&rel=0&autohide=1&showinfo=0"';
  }
  $output .= ' frameborder="0" allowfullscreen></iframe>';

  return $output;
}

/**
 * Preprocesses variables for a campaign sponsors, partners, and partner info.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.
 */
function dosomething_helpers_preprocess_partners_vars(&$vars) {
  // Returns partners, sponsors, and partner_info arrays.
  $partners_vars = dosomething_taxonomy_get_partners_vars($vars['nid']);
  // Gather any returned arrays.
  foreach ($partners_vars as $key => $values) {
    $vars[$key] = $values;
  }
  // Preprocess sponsor logos.
  if (isset($vars['sponsors'])) {
    foreach ($vars['sponsors'] as $delta => $sponsor) {
      $vars['sponsors'][$delta]['name'] = $sponsor['name'];
      // If there is a file present for sponsor logo:
      if (isset($sponsor['fid'])) {
        $img = dosomething_image_get_themed_image_by_fid($sponsor['fid'], 'wmax-423px', $sponsor['name']);
        $vars['sponsors'][$delta]['img'] = $img;
        // Set the display variable as the image.  This is outputted to tpl.
        $vars['sponsors'][$delta]['display'] = $img;
      }
      // Else if no file:
      else {
        // Return null so we won't display anything
        $vars['sponsors'][$delta]['display'] = NULL;
      }
    }
  }
  // Preprocess partner info modals.
  if (isset($vars['partner_info'])) {
    foreach ($vars['partner_info'] as $delta => $info) {
      // If video field is set:
      if (!empty($info['video'])) {
        $vars['partner_info'][$delta]['video'] = theme('dosomething_video_embed', array(
          'field' => $info['video'],
          'width' => 550,
          'height' => 300,
        ));
      }
      // If image landscape field is set:
      $image_node = $info['image'];
      if (!empty($image_node->field_image_landscape)) {
        $img = dosomething_image_get_themed_image($image_node->nid, 'landscape', '550x300');
        $vars['partner_info'][$delta]['image'] = $img;
      }
    }
  }
  // Preprocess a formatted list of partners.
  dosomething_helpers_format_partners_list($vars);
}

/**
 * Returns a list of partners formatted correctly
 *
 * If there are two partners, seperate them with "and"
 * If there are three or more partners a comma seperating each and "and" before the last.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.
 */
function dosomething_helpers_format_partners_list(&$vars) {
  $partners = $vars['partners'];
  $formatted_partners = '';

  foreach ($partners as $key => $partner) {
    $name = $partner['name'];
    // If there is a partner url set:
    if (isset($partner['url'])) {
      // Link to it.
      $name = l($name, $partner['url']);
    }
    $formatted_partners .= $name;
    if (count($partners) > 2 && $key == (count($partners) -2)) {
      $formatted_partners .= ' ' . t('and') .' ';
    }
    elseif (count($partners) > 2 && $key < (count($partners) -1)) {
      $formatted_partners .= ', ';
    }
    elseif ($key < (count($partners) -1)) {
      $formatted_partners .= ' ' . t('and') .' ';
    }
  }
  $vars['formatted_partners'] = $formatted_partners;
}

/**
 * Sets hero_image variables based on image_header / Cover Image field.
 */
function dosomething_helpers_preprocess_hero_images(&$vars) {
  // If the Campaign class is available:
  if (isset($vars['campaign'])) {
    $hero_nid = $vars['campaign']->image_header['nid'];
  }
  // Else check the regular Image Campaign Cover field value.
  elseif (isset($vars['field_image_campaign_cover'][0])) {
    $hero_nid = $vars['field_image_campaign_cover'][0]['entity']->nid;
  }

  if ($hero_nid) {
    $vars['hero_image']['desktop'] = dosomething_image_get_themed_image_url($hero_nid, 'landscape', '1440x810');
    $vars['hero_image']['mobile'] = dosomething_image_get_themed_image_url($hero_nid, 'square', '768x768');
  }
}

/**
 * Preprocesses variables for any custom settings.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.
 */
function dosomething_helpers_preprocess_custom_vars(&$vars) {
  if ($vars['type'] == 'campaign') {
    $campaign = $vars['campaign'];
    if ($campaign->variables['alt_color']) {
      $alt_color = $campaign->variables['alt_color'];
    }
    if ($campaign->variables['alt_bg_fid']) {
      $fid = $campaign->variables['alt_bg_fid'];
    }
  }
  else {
    $custom_vars = dosomething_helpers_get_variables($vars['nid']);
     if ($custom_vars['alt_color']) {
      $alt_color = $custom_vars['alt_color'];
    }
  }

  if (isset($alt_color)) {
    // Sanitize value for sanity's sake.
    $vars['alt_color'] = strip_tags($alt_color);
  }
  // Check for alt background File fid.
  if (isset($fid)) {
    $file = file_load($fid);
    $vars['alt_bg_src'] = file_create_url($file->uri);
  }
}

/**
 * Adds inline css into HEAD based on current state of vars.
 *
 * @param array $vars
 *   Node variables, passed from preprocess_node.
 */
function dosomething_helpers_add_inline_css(&$vars) {
  // Preprocess custom vars to see if any inline css needed.
  dosomething_helpers_preprocess_custom_vars($vars);

  // Check for alt_color variable.
  if (isset($vars['alt_color'])) {
    $alt_color = 'color: #' .  $vars['alt_color'] . ' !important;';
    $style_alt_color = '.inline--alt-color { ' . $alt_color . ' }';
    drupal_add_css($style_alt_color, $option['type'] = 'inline');
  }

  // Add hero background images if set
  if (isset($vars['hero_image']['mobile']) && isset($vars['hero_image']['desktop'])) {
    $style_hero_image = '[role="banner"].-hero {
        background-image: url("' . $vars['hero_image']['mobile'] . '");
      }

      @media only screen and (min-width: 768px) {
        [role="banner"].-hero {
          background-image: url("' . $vars['hero_image']['desktop'] . '");
        }
      }';
    drupal_add_css($style_hero_image, $option['type'] = 'inline');
  }

  // Set alt sponsor bg for modals
  if (isset($vars['alt_bg_src'])) {
    $alt_bg = 'background-image: url("' . $vars['alt_bg_src'] . '") !important;';
    $style_alt_background = '.inline--alt-bg { ' . $alt_bg . ' }';

    drupal_add_css($style_alt_background, $option['type'] = 'inline');
  }
}
