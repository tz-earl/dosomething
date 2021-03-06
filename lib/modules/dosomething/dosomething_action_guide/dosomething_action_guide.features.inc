<?php
/**
 * @file
 * dosomething_action_guide.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dosomething_action_guide_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dosomething_action_guide_node_info() {
  $items = array(
    'action_guide' => array(
      'name' => t('Action Guide'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
