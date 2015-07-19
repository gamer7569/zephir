
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


ZEPHIR_INIT_CLASS(Test_Optimizers_Cos) {

	ZEPHIR_REGISTER_CLASS(Test\\Optimizers, Cos, test, optimizers_cos, test_optimizers_cos_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Test_Optimizers_Cos, testInt) {


	RETURN_DOUBLE(cos(a));

}

PHP_METHOD(Test_Optimizers_Cos, testVar) {


	RETURN_DOUBLE(cos(a));

}

PHP_METHOD(Test_Optimizers_Cos, testIntValue1) {


	RETURN_DOUBLE(cos(4));

}

PHP_METHOD(Test_Optimizers_Cos, testIntValue2) {


	RETURN_DOUBLE(cos(16));

}

PHP_METHOD(Test_Optimizers_Cos, testIntParameter) {

	zval *a_param = NULL;
	int a;

	zephir_fetch_params(0, 1, 0, &a_param);

	a = zephir_get_intval(a_param);


	RETURN_DOUBLE(cos(a));

}

PHP_METHOD(Test_Optimizers_Cos, testVarParameter) {

	zval *a;

	zephir_fetch_params(0, 1, 0, &a);



	RETURN_DOUBLE(zephir_cos(a TSRMLS_CC));

}

