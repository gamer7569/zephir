
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Test_Optimizers_Sqrt) {

	ZEPHIR_REGISTER_CLASS(Test\\Optimizers, Sqrt, test, optimizers_sqrt, test_optimizers_sqrt_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Test_Optimizers_Sqrt, testInt) {


	RETURN_DOUBLE(sqrt(a));

}

PHP_METHOD(Test_Optimizers_Sqrt, testVar) {


	RETURN_DOUBLE(sqrt(a));

}

PHP_METHOD(Test_Optimizers_Sqrt, testIntValue1) {


	RETURN_DOUBLE(sqrt(4));

}

PHP_METHOD(Test_Optimizers_Sqrt, testIntValue2) {


	RETURN_DOUBLE(sqrt(16));

}

PHP_METHOD(Test_Optimizers_Sqrt, testIntParameter) {

	zval *a_param = NULL;
	int a;

	zephir_fetch_params(0, 1, 0, &a_param);

	a = zephir_get_intval(a_param);


	RETURN_DOUBLE(sqrt(a));

}

PHP_METHOD(Test_Optimizers_Sqrt, testVarParameter) {

	zval *a;

	zephir_fetch_params(0, 1, 0, &a);



	RETURN_DOUBLE(zephir_sqrt(a TSRMLS_CC));

}

