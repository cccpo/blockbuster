
#pragma once
#include <iostream>
#include <string>

using namespace::std;

class Message
{

private:
	string m;

public:
	void showErrorMessage(const char* message);
	void showWarningMessage(const char* message);

	int get();
};

