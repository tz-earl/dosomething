<?php
/**
 * @file
 * Preprocess functions for the dosomething_user module.
 */

/**
 * Implements template_preprocess_user_profile().
 */
function dosomething_user_preprocess_user_profile(&$variables) {

  // Array to contain all User Account information.
  $user_account = array();


  // Collect User Account data.
  $user_profile = $variables['user_profile'];

  $user_account['id']                  = isset($user_profile['uid']) ? $user_profile['uid'] : NULL;
  $user_account['username']            = isset($user_profile['username']) ? $user_profile['username'] : NULL;
  $user_account['email']               = isset($user_profile['mail']) ? $user_profile['mail'] : NULL;
  $user_account['first_name']          = isset($user_profile['field_first_name']['#items'][0]['safe_value']) ? $user_profile['field_first_name']['#items'][0]['safe_value'] : NULL;
  $user_account['last_name']           = isset($user_profile['field_last_name']['#items'][0]['safe_value']) ? $user_profile['field_last_name']['#items'][0]['safe_value'] : NULL;
  $user_account['birthday']            = isset($user_profile['field_birthdate']['#items'][0]['value']) ? $user_profile['field_birthdate']['#items'][0]['value'] : NULL;
  $user_account['mobile']              = isset($user_profile['field_mobile']['#items'][0]['safe_value']) ? $user_profile['field_mobile']['#items'][0]['safe_value'] : NULL;
  $user_account['location']['country'] = isset($user_profile['field_address']['#items'][0]['country']) ? $user_profile['field_address']['#items'][0]['country'] : NULL;
  $user_account['location']['state']   = isset($user_profile['field_address']['#items'][0]['administrative_area']) ? $user_profile['field_address']['#items'][0]['administrative_area'] : NULL;
  $user_account['location']['city']    = isset($user_profile['field_address']['#items'][0]['locality']) ? $user_profile['field_address']['#items'][0]['locality'] : NULL;
  $user_account['location']['zip']     = isset($user_profile['field_address']['#items'][0]['postal_code']) ? $user_profile['field_address']['#items'][0]['postal_code'] : NULL;
  $user_account['location']['street']  = isset($user_profile['field_address']['#items'][0]['thoroughfare']) ? $user_profile['field_address']['#items'][0]['thoroughfare'] : NULL;
  $user_account['location']['premise'] = isset($user_profile['field_address']['#items'][0]['premise']) ? $user_profile['field_address']['#items'][0]['premise'] : NULL;


  // Collect Address information that user has provided.
  $address = array();

  foreach($user_account['location'] as $key => $value) {
    if (!empty($value)) {
      $address[$key] = $value;
    }
  }

  $user_account['address'] = $address;


  // Collect Signed Up Campaigns data.
  $user_account['campaigns_signedup'] = $variables['elements']['campaigns_signedup'];
  

  // Collect Recommended Campaigns data.
  $user_account['campaigns_recommended'] = $variables['elements']['campaigns_recommended'];
  

  $variables['user_account'] = $user_account;

}