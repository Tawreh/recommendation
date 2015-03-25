<?php

/**
 * Implementation of hook_views_default_views().
 */
function recommendation_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'my_recommendations';
  $view->description = 'A view of recommended items for the logged in user.';
  $view->tag = 'default';
  $view->base_table = 'recommendation';
  $view->human_name = 'My recommendations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My recommendations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Recommendation: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'recommendation';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Recommendation: Product price */
  $handler->display->display_options['fields']['recommendation_price']['id'] = 'recommendation_price';
  $handler->display->display_options['fields']['recommendation_price']['table'] = 'field_data_recommendation_price';
  $handler->display->display_options['fields']['recommendation_price']['field'] = 'recommendation_price';
  $handler->display->display_options['fields']['recommendation_price']['element_type'] = '0';
  $handler->display->display_options['fields']['recommendation_price']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['recommendation_price']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['recommendation_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['recommendation_price']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['recommendation_price']['field_api_classes'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'my-recommendations';
  $translatables['my_recommendations'] = array(
    t('Master'),
    t('My recommendations'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Id'),
    t('.'),
    t(','),
    t('Product price'),
    t('Page'),
  );

  $views[$view->name] = $view;

  return $views;
}