#include <iostream> 
#include "protocol.h"
using namespace std;

void init(void){
	cout << "Plugin 'div' is initialized" << endl;
}

void destroy(void){
	cout << "Plugin 'div' is de-initialized" << endl;
}

void run(void){
	int x, y;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;
	
	if(y != 0)
		cout << "Result: " << x/y << endl;
	else
		cout << "Can not divide on zero! " << endl;
	 
}

const char* can_do(void){
	return "dividing";
}



