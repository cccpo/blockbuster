#include "Value.h"

Value::Value() {

}

Value::~Value() {

}

//‹ó‚Å‚ ‚é‚©‚ğ”»’è‚·‚éŠÖ”
bool Value::IsEmpty(int i) {
	if (i != 0) {
		return false;
	}

	return true;
}

