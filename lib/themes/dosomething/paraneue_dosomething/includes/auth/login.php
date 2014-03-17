<?php

/**
 * Adds login modal to page markup.
 *
 * Implements hook_page_alter().
 */
function paraneue_dosomething_page_alter_login(&$page) {
  if (!user_is_logged_in()){
    $page['page_bottom']['login'] = array(
      '#prefix' => '<script type="text/cached-modal" id="modal--login">',
      '#suffix' => '</script>',
      'modal_close' => array(
        '#markup' => '<a href="#" class="js-close-modal modal-close-button">×</a>'
      ),
      'login' => drupal_get_form('user_login_block')
    );

    $page['page_bottom']['register'] = array(
      '#prefix' => '<script type="text/cached-modal" id="modal--register">',
      '#suffix' => '</script>',
      'modal_close' => array(
        '#markup' => '<a href="#" class="js-close-modal modal-close-button">×</a>'
      ),
      'register' => drupal_get_form('user_register_form')
    );
  }
}

/**
 * Configures login form.
 *
 * Implements hook_form_alter().
 */
function paraneue_dosomething_form_alter_login(&$form, &$form_state, $form_id) {
  if( $form_id == "user_login_block" || $form_id == 'user_login' ) {
    $form['#attributes']['class'] = 'auth--login';

    $form['message'] = array(
      '#type' => 'item',
      '#markup' => '<h2 class="auth--header">Log in to get started!</h2>',
      '#weight' => -199
    );

    $form['create-account-link'] = array(
      '#type' => 'item',
      '#markup' => '<p class="auth--toggle-link"><a href="/user/registration" data-cached-modal="#modal--register" class="js-modal-link">Create a DoSomething.org Account</a><br/><a href="/user/password">Forgot password?</a></p>',
      '#weight' => 500
    );

    unset($form['links']);

    // After build form changes.
    $form['#after_build'][] = 'paraneue_dosomething_login_after_build';
  }
}

/**
 * Custom afterbuild on login form.
 *
 * @param array - $form
 *  A drupal form array.
 * @param array - $form_state
 *  A drupal form_state array.
 *
 * @return - array - $form
 *  Modified drupal form.
 */
function paraneue_dosomething_login_after_build($form, &$form_state) {
  // Customize field elements.
  $form['name']['#title'] = 'Email address or cell number';
  $form['name']['#attributes']['placeholder'] = 'Email address or cell number';
  unset($form['name']['#description']);
 
  $form['pass']['#attributes']['placeholder'] = 'Password';
  unset($form['pass']['#description']);

  return $form; 
}
