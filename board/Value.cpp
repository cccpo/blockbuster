#include "Value.h"

Value::Value() {

}

Value::~Value() {

}

//��ł��邩�𔻒肷��֐�
bool Value::IsEmpty(int i) {
	if (i != 0) {
		return false;
	}

	return true;
}

