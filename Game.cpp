#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <memory>


#include "message/Message.h"
#include "window/window.h"

using std::cout;
using std::endl;

//game
void StartGame() {
	
	cout << "Game Start!" << endl;
}


//main
int main() {
	Message me;
	window wi;
	int a = wi.getWindowSize();


	//me.showErrorMessage("");
	
	//cout << "HelloWOrld!" << endl;
	
	//ƒQ[ƒ€ŠJŽn
	StartGame();
	

	return 0;
}
