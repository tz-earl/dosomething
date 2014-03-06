<?php

/**
 * Sends a Mobilecommons API request to opt-in user with given campaign title.
 *
 * @param object $account
 *   The user object of user to opt-in.
 * @param int $lid
 *   The opt-in path to use for opt-in.
 * @param string $title
 *   Optional -- The campaign title the user has signed up for.
 *
 * @return mixed
 *   A Mobilecommons object, or FALSE if error.
 */
function dosomething_signup_mobilecommons_opt_in($account, $lid, $title = NULL) {
  // Make sure mobilecommons module is enabled.
  if (!module_exists('mobilecommons')) { return; }

   // If user doesn't have mobile number, exit function.
  $mobile = dosomething_user_get_mobile($account);
  if (!$mobile) {
    return FALSE;
  }

  try {
    // If valid args for given $user:
    if ($args = dosomething_signup_get_mobilecommons_vars($account, $lid, $title)) {
      // Submit Mobilecommons request.
      return mobilecommons_request('opt_in', $args);
    }
  }
  catch (Exception $e) {
    // Log the error.
    watchdog('dosomething_signup', $e, array(), WATCHDOG_ERROR);
  }
  return FALSE;
}

/**
 * Prepares array of arguments to pass to a Mobilecommons opt-in request.
 *
 * @param object $account
 *   The user object of user to opt-in.
 * @param int $lid
 *   The opt-in path to use for opt-in.
 * @param string $title
 *   Optional -- The campaign title the user has signed up for.
 *
 * @return mixed
 *   Array of arguments to pass to a Mobilecommons request, or FALSE if no mobile.
 */
function dosomething_signup_get_mobilecommons_vars($account, $lid, $title = NULL) {
  $args = array(
    'opt_in_path[]' => $lid,
    'person[phone]' => dosomething_user_get_mobile($account),
    'person[email]' => $account->mail,
  );
  if ($first_name = dosomething_user_get_field('field_first_name', $account)) {
    $args['person[first_name]'] = $first_name;
  }
  // Expected DOB format is YYYY-MM-DD.
  if ($dob = dosomething_user_get_birthdate('Y-m-d', $account)) {
    $args['person[date_of_birth]'] = $dob;
  }
  if (isset($title)) {
    $args['person[campaign_name]'] = $title;
  }
  return $args;
}