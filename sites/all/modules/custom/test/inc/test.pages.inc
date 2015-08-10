<?php 
	function _list_items(){
		$items['product'] ='admin/test/add/product';
		return $items;
	}
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
		$category = taxonomy_vocabulary_machine_name_load('category'); 
		$categories = taxonomy_get_tree($category->vid);
		foreach ($categories as $key => $value) {
			$cate[$value->tid] = $value->name;
		}
		$form['category'] = array(
		  '#type'   => 'select',
		  '#title'  => t('Category'),
		  '#options'=> $cate,
		  '#required'=> TRUE,
		);
		/**
		* Review
		*/
		$program = _get_program();
		foreach ($program as $key => $value) {
			$options[$value['id']] = $value['name'];
		}
		$form['program']  = array(
		  '#type'   => 'select',
		  '#title'  => t('Program'),
		  '#options'=> $options,
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
	      '#title'    => t('Sale price'),
	      '#default_value' => '',
	      '#size' 	  => 60,
	      '#maxlength'=> 128,
	      '#required' => TRUE,
		);
		$form['point_price'] =array(
		  '#type' 	  => 'textfield',
	      '#title'    => t('Point price'),
	      '#default_value' => '',
	      '#size' 	  => 60,
	      '#maxlength'=> 128,
	      '#required' => TRUE,
		);
		$freight = _get_freight();
		foreach ($freight as $key => $value) {
			$options[$value['value']] = $value['code'];
		}
		$form['type_freigth'] = array(
		  '#type' 	  => 'select',
	      '#title'    => t('Type freight'),
	      '#title'  => t('Freight'),
		  '#options'=> $options,
		  '#required'=> TRUE,
		);
		$form['finish_price'] = array(
			'#type' 	  => 'textfield',
			'#title'    => t('Finish price'),
			'#title'  => t('Freight'),
			'#required'=> TRUE,	
		);
    	$form['#submit'][] = '_test_product_save';
    	return system_settings_form($form);
	}

	function _test_product_edit($id){
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
		$category = taxonomy_vocabulary_machine_name_load('category'); 
		$categories = taxonomy_get_tree($category->vid);
		foreach ($categories as $key => $value) {
			$cate[$value->tid] = $value->name;
		}
		$form['category'] = array(
		  '#type'   => 'select',
		  '#title'  => t('Category'),
		  '#options'=> $cate,
		  '#required'=> TRUE,
		);
		/**
		* Review
		*/
		$program = _get_program();
		foreach ($program as $key => $value) {
			$options[$value['id']] = $value['name'];
		}
		$form['program']  = array(
		  '#type'   => 'select',
		  '#title'  => t('Program'),
		  '#options'=> $options,
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
	      '#title'    => t('Sale Price'),
	      '#default_value' => '',
	      '#size' 	  => 60,
	      '#maxlength'=> 128,
	      '#required' => TRUE,
		);
		$form['type_freigth'] = array(
		  '#type' 	  => 'select',
	      '#title'    => t('Type Freight'),
	      '#title'  => t('Freight'),
		  '#options'=> taxonomy_get_tree(1),
		  '#required'=> TRUE,
		);
		$form['finish_price'] = array(
			'#type' 	  => 'textfield',
			'#title'    => t('Finish price'),
			'#title'  => t('Freight'),
			'#required'=> TRUE,	
		);
    	$form['#submit'][] = '_test_product_save';
    	return system_settings_form($form);	
	}

	function _test_program(){
		$form['name'] = array(
			'#type' => 'textfield',
			'#title'=> t('Name'),
			'#required'=> TRUE,
		);
		$form['value'] = array(
			'#type' => 'textfield',
			'#title'=> t('Value'),
			'#required'=> TRUE,
		);
		$form['#submit'][] = '_test_program_save';
    	return system_settings_form($form);
	}

	function _test_program_edit($id){
		$form['name'] = array(
		'#type' => 'textfield',
		'#title'=> t('Name'),
		'#required'=> TRUE,
		);
		$form['value'] = array(
			'#type' => 'textfield',
			'#title'=> t('Value'),
			'#required'=> TRUE,
		);
		$form['#submit'][] = '_test_program_save';
    	return system_settings_form($form);
	}

	function _test_freight(){
		$form['code'] = array(
			'#type' => 'textfield',
			'#title'=> t('Code'),
			'#required'=> TRUE,
		);
		$form['type'] = array(
			'#type' => 'textfield',
			'#title'=> t('Type'),
			'#required'=> TRUE,
		);
		$form['#submit'][] = '_test_freigth_save';
    	return system_settings_form($form);
	}
	/**
	*
	*/
	function _edit_test_freight($id){
		$form['code'] = array(
			'#type' => 'textfield',
			'#title'=> t('Code'),
			'#required'=> TRUE,
		);
		$form['type'] = array(
			'#type' => 'textfield',
			'#title'=> t('Value'),
			'#required'=> TRUE,
		);
		$form['#submit'][] = '_test_program_save';
    	return system_settings_form($form);
	}
	/**
	*
	*/
	function _test_freight_validate($form, &$form_state){
		if(is_numeric($form_state['values']['code']) == FALSE){
			 form_set_error('code', t('Code must be numeric'));
		}
		if(is_numeric($form_state['values']['type']) == FALSE){
			 form_set_error('type', t('Value must be numeric'));
		}
	}
	/**
	*
	*/
	function _test_program_validate($form, &$form_state){
		if(is_numeric($form_state['values']['value']) == FALSE){
			form_set_error('value', t('Value must be numeric'));	
		}
	}
	function _test_product_validate($form, &$form_state){
		if(is_numeric($form_state['values']['cost'])== FALSE){
			form_set_error('cost', t('Value must be numeric'));		
		}
		if (is_numeric($form_state['values']['point_price'])==FALSE) {
			form_set_error('point_price ', t('Value must be numeric'));		
		}
	}
	/**
	*
	*/
	function _test_product_save($form, &$form_state){
		db_insert('product')
		->fields(array(
			'sku'=> $form_state['values']['sku'], 
			'name'=>$form_state['values']['name'],
			'cost'=>(int)$form_state['values']['cost'],
			'frid'=>(int)$form_state['values']['type_freigth'],
			'pid' =>(int)$form_state['values']['program'],
			'category'=>(int)$form_state['values']['category'],
			'sale_price'=>(int)$form_state['values']['sale_price'],
			'price_point'=>(int)$form_state['values']['point_price'],
			'finish_price'=>(int)$form_state['values']['finish_price'],
				)
			)
		->execute();
	}
	/**
	*
	*
	*/
	function _test_freigth_save($form, &$form_state){
		db_insert('freight')
		->fields(array(
			'code'=> (int)$form_state['values']['code'], 
			'value'=>$form_state['values']['type']
				)
			)
		->execute();
	}
	/**
	*
	*
	*/
	function _test_program_save($form, &$form_state){
		db_insert('program')
		->fields(array(
			'name'=> $form_state['values']['name'], 
			'value'=>$form_state['values']['value']
				)
			)
		->execute();
	}
?>