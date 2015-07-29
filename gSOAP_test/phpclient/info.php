<?php
	echo "hello";
	$ws = 'http://localhost:8011/demo.wsdl';
	try {
		$soap = new SoapClient($ws);
	}
	catch (SoapFault $e) {
		echo $e;
	}
	
	echo "<br />";
	print_r($soap->__getFunctions());
	echo "<br />";
	print_r($soap->__getTypes());
	
	class AddA {
		var $a = 0.0;
		var $b = 0.0;
	};
	$a_arg = new AddA();
	$a_arg->a = 2.1;
	$a_arg->b = 2.2;
	$a_res = $soap->AddA($a_arg);
	echo "<br />";
	print_r($a_res->res);
	
	class AddB {
		var $a = 0.0;
		var $b = 0.0;
	};
	$b_arg = new AddB();
	$b_arg->a = 2.1;
	$b_arg->b = 2.2;
	$soap->AddB($b_arg);
	
	var_dump($soap->AddC());
?>