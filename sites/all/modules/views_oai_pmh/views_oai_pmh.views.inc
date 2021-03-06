<?php
/**
 * @file
 * Views include file with views hooks.
 */

/**
 * Implementation of hook_views_plugins().
 */
function views_oai_pmh_views_plugins() {
  $path = drupal_get_path('module', 'views_oai_pmh');

  $style_defaults = array(
    'path' => $path . '/plugins',
    'parent' => 'views_oai_pmh',
    'theme' => 'views_oai_pmh_response',
    'theme path' => $path . '/theme',
    'theme file' => 'views_oai_pmh.theme.inc',
    'uses row plugin' => TRUE,
    'uses fields' => TRUE,
    'uses options' => TRUE,
    'type' => 'oai-pmh',
  );

  return array(
    'display' => array (
      'views_oai_pmh' => array(
        'title' => t('OAI-PMH'),
        'help' => t('Export the view results to an OAI feed'),
        'path' => $path . '/plugins',
        'handler' => 'views_oai_pmh_plugin_display',
        'parent' => 'page',
        'uses hook menu' => TRUE,
        'use ajax' => FALSE,
        'use pager' => TRUE,
        'accept attachments' => FALSE,
        'admin' => t('OAI-PMH'),
        'help topic' => 'display-oai',
      ),
    ),
    'style' => array(
      'views_oai_pmh' => array(
        // this isn't really a display but is necessary so the file can
        // be included.
        'no ui' => TRUE,
        'handler' => 'views_oai_pmh_plugin_style',
        'path' => $path . '/plugins',
        'theme path' => $path . '/theme',
        'theme file' => 'views_oai_pmh.theme.inc',
        'additional themes' => array(
          'views_oai_pmh_identify_body' => 'style',
      		'views_oai_pmh_metadataformats_body' => 'style',
          'views_oai_pmh_record_header' => 'style',
        ),
        'additional themes base' => 'views_oai_pmh',
       ),
      'views_oai_pmh_dc' => array(
        'title' => t('OAI-PMH (dc)'),
        'help' => t('Export the display as a Dublin Core OAI-PMH feed'),
        'handler' => 'views_oai_pmh_plugin_style_dc',
        'oai headers' => array('Content-Type' => 'text/xml'),
        'additional themes' => array(
          'views_oai_pmh_dc_record' => 'style',
          'views_oai_pmh_plugin_row_dc' => 'style',
          'views_oai_pmh_plugin_row_dc_fields' => 'style',
        ),
        'additional themes base' => 'views_oai_pmh',
      ) + $style_defaults,
 /*     'views_oai_pmh_etdms' => array(
        'title' => t('OAI-PMH (ETDMS)'),
        'help' => t('Export the display as a ETDMS OAI-PMH feed'),
        'handler' => 'views_oai_pmh_plugin_style_etdms',
        'oai headers' => array('Content-Type' => 'text/xml'),
        'additional themes' => array(
          'views_oai_pmh_etdms_record' => 'style',
          'views_oai_pmh_plugin_row_etdms' => 'style',
        ),
        'additional themes base' => 'views_oai_pmh',
      ) + $style_defaults,
*/
    ),
    'row' => array(
      'dc' => array(
        'title' => t('Dublin Core Fields'),
        'help' => t('Displays the fields with as Dublin Core elements.'),
        'path' => $path . '/plugins',
        'handler' => 'views_oai_pmh_plugin_row_dc',
        'theme' => 'views_oai_pmh_row_dc_fields',
        'parent' => 'views_oai_pmh',
        'theme path' => $path . '/theme',
        'theme file' => 'views_oai_pmh.theme.inc',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'help topic' => 'style-row-fields',
      ) ,
/*      'etdms' => array(
        'title' => t('ETDMS Fields'),
        'help' => t('Displays the fields with as ETDMS elements.'),
        'path' => $path . '/plugins',
        'handler' => 'views_oai_pmh_plugin_row_etdms',
        'theme' => 'views_oai_pmh_row_etdms_fields',
        'parent' => 'views_oai_pmh',
        'theme path' => $path . '/theme',
        'theme file' => 'views_oai_pmh.theme.inc',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'help topic' => 'style-row-fields',
      ) ,
*/      ),
    );
}
