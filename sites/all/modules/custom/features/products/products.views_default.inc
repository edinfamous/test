<?php
/**
 * @file
 * products.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function products_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'test';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'product';
  $view->human_name = 'test';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'test';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Product: Sku */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  /* Field: Product: Category */
  $handler->display->display_options['fields']['category']['id'] = 'category';
  $handler->display->display_options['fields']['category']['table'] = 'product';
  $handler->display->display_options['fields']['category']['field'] = 'category';
  /* Field: Product: Finish_price */
  $handler->display->display_options['fields']['finish_price']['id'] = 'finish_price';
  $handler->display->display_options['fields']['finish_price']['table'] = 'product';
  $handler->display->display_options['fields']['finish_price']['field'] = 'finish_price';
  /* Field: Product: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'product';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Product: Price_point */
  $handler->display->display_options['fields']['price_point']['id'] = 'price_point';
  $handler->display->display_options['fields']['price_point']['table'] = 'product';
  $handler->display->display_options['fields']['price_point']['field'] = 'price_point';
  $handler->display->display_options['fields']['price_point']['precision'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'products';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'test';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['test'] = $view;

  return $export;
}
