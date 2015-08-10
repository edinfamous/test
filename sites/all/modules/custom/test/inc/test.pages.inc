<?php 
	function _test_product(){
		$form['sku'] = array(
		  '#type' 	  => 'textfield',
	      '#title' 	  => t('SKU'),
	      '#default_value' => '',
	      '#size' 	  => 60,
	      '#maxlength'=> 128,
	      '#required' => TRUE,
		);
		$form['name'] = array(
		  '#type' 	  => 'textfield',
	      '#title'    => t('Name'),
	      '#default_value' => '',
	      '#size' 	  => 60,
	      '#maxlength'=> 128,
	      '#required' => TRUE,
		);
		$form['category'] = array(
		  '#type'   => 'select',
		  '#title'  => t('Category'),
		  '#options'=> taxonomy_get_tree(1),
		  '#required'=> TRUE,
		);
		/**
		* Review
		*/
		$form['program']  = array(
		  '#type'   => 'select',
		  '#title'  => t('Category'),
		  '#options'=> taxonomy_get_tree(1),
		  '#required'=> TRUE,
		);
		$form['cost'] = array(
		  '#type' 	  => 'textfield',
	      '#title'    => t('Cost'),
	      '#default_value' => '',
	      '#size' 	  => 60,
	      '#maxlength'=> 128,
	      '#required' => TRUE,
		);
		$form['sale_price'] =array(
		  '#type' 	  => 'textfield',
	      '#title'    => t('Cost'),
	      '#default_value' => '',
	      '#size' 	  => 60,
	      '#maxlength'=> 128,
	      '#required' => TRUE,
		);
		$form['type_freigth'] = array(
		  '#type' 	  => 'select',
	      '#title'    => t('Cost'),
	      '#title'  => t('Category'),
		  '#options'=> taxonomy_get_tree(1),
		  '#required'=> TRUE,
		);
    	$form['#submit'][] = '_test_product_save';
    	return system_settings_form($form);
	}

	function test_validate($node, $form, &$form_state){
		
	}

	function _test_product_save($form, &$form_state){

	}
?>