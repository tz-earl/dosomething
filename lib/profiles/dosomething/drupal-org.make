; Contrib modules, themes and libraries

api = 2
core = 7.x

; MODULES

; Address Field
projects[addressfield][version] = "1.0-beta5"
projects[addressfield][subdir] = "contrib"
; Allows addressfield as form element: https://drupal.org/node/970048
projects[addressfield][patch][] = https://drupal.org/files/addressfield-element_info-970048-71.patch

; Admin menu
projects[admin_menu][version] = "3.0-rc4"
projects[admin_menu][subdir] = "contrib"

; Apachesolr
projects[apachesolr][version] = "1.6"
projects[apachesolr][subdir] = "contrib"

; Apachesolr Views
projects[apachesolr_views][version] = "1.0-beta2"
projects[apachesolr_views][subdir] = "contrib"

; Blockreference
projects[blockreference][version] = "1.16"
projects[blockreference][subdir] = "contrib"

; CDN
projects[cdn][version] = "2.6"
projects[cdn][subdir] = "contrib"

; Ctools
projects[ctools][version] = "1.4"
projects[ctools][subdir] = "contrib"

; Date
projects[date][version] = "2.8"
projects[date][subdir] = "contrib"

; Diff
projects[diff][version] = "3.2"
projects[diff][subdir] = "contrib"

; Entity
projects[entity][version] = "1.5"
projects[entity][subdir] = "contrib"

; Entity Autocomplete
projects[entity_autocomplete][version] = "1.0-beta3"
projects[entity_autocomplete][subdir] = "contrib"

; Entity Connect
projects[entityconnect][version] = "1.0-rc1"
projects[entityconnect][subdir] = "contrib"

; Entity Reference
projects[entityreference][version] = "1.1"
projects[entityreference][subdir] = "contrib"

; Features
projects[features][version] = "2.0"
projects[features][subdir] = "contrib"

; Field Collection
projects[field_collection][type] = "module"
; Fixes https://drupal.org/node/2141781, https://github.com/DoSomething/dosomething/issues/2561.
projects[field_collection][download][type] = "git"
projects[field_collection][download][revision] = "ae778f23f8e0968fa3a10a727c6e26c6e63309a0"
projects[field_collection][subdir] = "contrib"

; Field Group
projects[field_group][version] = "1.3"
projects[field_group][subdir] = "contrib"

; File Entity
projects[file_entity][version] = "2.0-alpha3"
projects[file_entity][subdir] = "contrib"

; Flag
projects[flag][version] = "3.5"
projects[flag][subdir] = "contrib"

; Google Analytics
projects[google_analytics][version] = "1.4"
projects[google_analytics][subdir] = "contrib"

; Http Client
projects[http_client][version] = "2.4"
projects[http_client][subdir] = "contrib"

; Internationalization (required for Sitemap, among others)
projects[i18n][version] = "1.11"
projects[i18n][subdir] = "contrib"

; Localization update
projects[l10n_update][version] = "1.0"
projects[l10n_update][subdir] = "contrib"

; Libraries
projects[libraries][version] = "2.2"
projects[libraries][subdir] = "contrib"

; Link
projects[link][version] = "1.2"
projects[link][subdir] = "contrib"

; Markdown
projects[markdown][version] = "1.2"
projects[markdown][subdir] = "contrib"

; Metatag
projects[metatag][version] = "1.0-beta9"
projects[metatag][subdir] = "contrib"

; Mobile Commons
projects[mobilecommons][version] = "1.1"
projects[mobilecommons][subdir] = "contrib"

; Module Filter
projects[module_filter][version] = "2.0-alpha2"
projects[module_filter][subdir] = "contrib"

; OAuth
projects[oauth][version] = "3.2"
projects[oauth][subdir] = "contrib"
; See https://www.drupal.org/node/2328685
projects[oauth][patch][] = "https://www.drupal.org/files/issues/oauth-OAuth-PHP-library-Authorization-Header-parameters-separator-2328685-1.patch"

; Optimizely
projects[optimizely][version] = "2.14"
projects[optimizely][subdir] = "contrib"

; Pathauto
projects[pathauto][version] = "1.2"
projects[pathauto][subdir] = "contrib"

; POTX (Translation template extractor)
projects[potx][version] = "1.0"
projects[potx][subdir] = "contrib"

; Redirect
projects[redirect][version] = "1.0-rc1"
projects[redirect][subdir] = "contrib"

; Redis
projects[redis][version] = "2.6"
projects[redis][subdir] = "contrib"

; Services
projects[services][version] = "3.10"
projects[services][subdir] = "contrib"

; Strongarm
projects[strongarm][version] = "2.0"
projects[strongarm][subdir] = "contrib"

; Taxonomy Access Fix
projects[taxonomy_access_fix][version] = "2.1"
projects[taxonomy_access_fix][subdir] = "contrib"

; Token
projects[token][version] = "1.5"
projects[token][subdir] = "contrib"

; UUID
projects[uuid][version] = "1.0-alpha5"
projects[uuid][subdir] = "contrib"

; UUID Features
projects[uuid_features][version] = "1.0-alpha4"
projects[uuid_features][subdir] = "contrib"

; Variable
projects[variable][version] = "2.5"
projects[variable][subdir] = "contrib"

; Varnish
projects[varnish][version] = "1.0-beta2"
projects[varnish][subdir] = "contrib"

; View Unpublished
projects[view_unpublished][version] = "1.1"
projects[view_unpublished][subdir] = "contrib"
projects[view_unpublished][patch][] = "https://drupal.org/files/view_unpublished_content_admin-1192074-60.patch"

; Views
projects[views][version] = "3.8"
projects[views][subdir] = "contrib"

; Views Data Export
projects[views_data_export][version] = "3.0-beta8"
projects[views_data_export][subdir] = "contrib"

; XML Sitemap
projects[xmlsitemap][version] = "2.0"
projects[xmlsitemap][subdir] = "contrib"


; GIT PROJECTS

; Conductor
projects[conductor][type] = "module"
projects[conductor][download][type] = "git"
projects[conductor][download][url] = "https://github.com/DoSomething/Conductor.git"
projects[conductor][subdir] = "contrib"

; Conductor SMS
projects[conductor_sms][type] = "module"
projects[conductor_sms][download][type] = "git"
projects[conductor_sms][download][url] = "https://github.com/DoSomething/conductor_sms.git"
projects[conductor_sms][subdir] = "contrib"

; Message Broker Producer
projects[message_broker_producer][type] = "module"
projects[message_broker_producer][download][type] = "git"
projects[message_broker_producer][download][url] = "https://github.com/DoSomething/message_broker_producer.git"
projects[message_broker_producer][subdir] = "contrib"


; DEVELOPMENT

; Devel
projects[devel][version] = "1.4"
projects[devel][subdir] = "contrib"

; Coder
projects[coder][version] = "2.2"
projects[coder][subdir] = "contrib"

; Stage File Proxy
projects[stage_file_proxy][version] = "1.6"
projects[stage_file_proxy][subdir] = "contrib"


; LIBRARIES

; DSAPI PHP Library
;libraries[dsapi][download][type] = "git"
;libraries[dsapi][download][url] = "git@github.com:DoSomething/dsapi-php.git"

; Message Broker PHP Library
libraries[messagebroker-phplib][download][type] = "git"
libraries[messagebroker-phplib][download][url] = "https://github.com/DoSomething/messagebroker-phplib.git"

; Message Broker Configuration
libraries[messagebroker-config][download][type] = "git"
libraries[messagebroker-config][download][url] = "https://github.com/DoSomething/messagebroker-config.git"

; Mobile Commons PHP
libraries[mobilecommons-php][download][type] = "git"
libraries[mobilecommons-php][download][url] = "https://github.com/DoSomething/mobilecommons-php.git"

; Predis
libraries[predis][download][type] = "git"
libraries[predis][download][url] = "https://github.com/nrk/predis.git"
; Pin to 0.8 release, which still has the lib directory.
libraries[predis][download][revision] = "4123fcd85d61354c6c9900db76c9597dbd129bf6"

; Zendesk PHP
libraries[zendesk][download][type] = "git"
libraries[zendesk][download][url] = "https://github.com/zendesk/zendesk_api_client_php"
; Use last working commit. See https://github.com/DoSomething/dosomething/issues/2064
libraries[zendesk][download][revision] = "6aa9662fb1ed45b6bcc93ef9e1e4ab14685e80ac"
