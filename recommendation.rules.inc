<?php

/**
 * Implementation of hook_rules_action_info().
 */
function recommendation_rules_action_info() {
  $actions = array();

  $actions['recommendation_create_recommendation'] = array(
    'label' => t('Create a recommendation'),
    'parameter' => array(
      'order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
      ),
      'product' => array(
        'type' => 'commerce_product',
        'label' => t('Product'),
      ),
    ),
    'group' => t('Recommendations'),
    'callbacks' => array(
      'execute' => 'recommendation_create_recommendation',
    ),
  );

  return $actions;
}

/**
 * Create a recommendation.
 */
function recommendation_create_recommendation($order, $product) {
  $recommendation = entity_create('recommendation', array(
    'type' => 'recommendation',
    'date' => time(),
    'uid' => $order->order_id,
    'product_id' => $product->product_id,
    'recommendation_price' => $product->commerce_price,
  ));

  $recommendation->save();
}
