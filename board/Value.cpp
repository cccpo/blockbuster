#include "Value.h"

Value::Value() {

}

Value::~Value() {

}

//空であるかを判定する関数
bool Value::IsEmpty(int i) {
	if (i != 0) {
		return false;
	}

	return true;
}

