<?php

/**
 * Implementation of hook_entity_property_info().
 */
function recommendations_entity_property_info() {
  $info = array();
  $properties = &$info['recommendation']['properties'];

  $properties['id'] = array(
    'label' => t('Recommendation ID'),
    'description' => t('The internal numeric ID of the recommendation entity.'),
    'type' => 'integer',
    'schema field' => 'id',
  );

  $properties['date'] = array(
    'label' => t('Recommendation date'),
    'description' => t('The date the recommendation entity was created.'),
    'type' => 'integer',
    'schema field' => 'date',
  );

  $properties['time_ago'] = array(
    'label' => t('Recommendation time ago'),
    'description' => t('Time ago the recommendation was created.'),
    'type' => 'date',
    'getter callback' => 'recommendation_get_properties',
    'computed' => TRUE,
  );

  $properties['uid'] = array(
    'label' => t('Creator ID'),
    'description' => t('The user ID of the person who created this recommendation.'),
    'type' => 'integer',
    'schema field' => 'uid',
  );

  $properties['product'] = array(
    'label' => t('Product ID'),
    'description' => t('The internal numeric ID of the recommended product entity.'),
    'type' => 'integer',
    'schema field' => 'product_id',
  );

  return $properties;
}