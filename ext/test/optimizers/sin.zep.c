
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


ZEPHIR_INIT_CLASS(Test_Optimizers_Sin) {

	ZEPHIR_REGISTER_CLASS(Test\\Optimizers, Sin, test, optimizers_sin, test_optimizers_sin_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Test_Optimizers_Sin, testInt) {


	RETURN_DOUBLE(sin(a));

}

PHP_METHOD(Test_Optimizers_Sin, testVar) {


	RETURN_DOUBLE(sin(a));

}

PHP_METHOD(Test_Optimizers_Sin, testIntValue1) {


	RETURN_DOUBLE(sin(4));

}

PHP_METHOD(Test_Optimizers_Sin, testIntValue2) {


	RETURN_DOUBLE(sin(16));

}

PHP_METHOD(Test_Optimizers_Sin, testIntParameter) {

	zval *a_param = NULL;
	int a;

	zephir_fetch_params(0, 1, 0, &a_param);

	a = zephir_get_intval(a_param);


	RETURN_DOUBLE(sin(a));

}

PHP_METHOD(Test_Optimizers_Sin, testVarParameter) {

	zval *a;

	zephir_fetch_params(0, 1, 0, &a);



	RETURN_DOUBLE(zephir_sin(a TSRMLS_CC));

}

