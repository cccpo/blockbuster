
#pragma once
#include <iostream>
#include <string>

using namespace::std;

//���b�Z�[�W�̂������s���N���X
class Message
{

private:
	string m;

public:
	void showErrorMessage(const char* message);
	void showWarningMessage(const char* message);

	int get();
};

