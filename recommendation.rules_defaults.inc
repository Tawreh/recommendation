<?php

/**
 * Implementation of hook_default_rules_configuration().
 */
function recommendation_default_rules_configuration() {
  $configs = array();

  $rule = rules_reaction_rule();
  $rule->label = 'Create basic recommendation';
  $rule->requires = array(
    'rules',
    'recommendation',
    'commerce_cart',
  );
  $rule->event('commerce_cart_product_add');

  $rule = rules_import('
{ "rules_create_recommendation" : {
    "LABEL" : "Create recommendation",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "recommendation", "commerce_cart" ],
    "ON" : { "commerce_cart_product_add" : [] },
    "IF" : [
      { "user_has_role" : {
          "account" : [ "commerce-order:owner" ],
          "roles" : { "value" : { "2" : "2" } }
        }
      }
    ],
    "DO" : [
      { "recommendation_create_recommendation" : { "order" : [ "commerce-order" ], "product" : [ "commerce-product" ] } }
    ]
  }
}
  ');

  $configs['rules_create_recommendation'] = $rule;

  return $configs;
}