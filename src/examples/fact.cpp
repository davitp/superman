#include <iostream> 
#include "protocol.h"
using namespace std;
int fact(int x);

void init(void){
	cout << "Plugin 'fact' is initialized" << endl;
}

void destroy(void){
	cout << "Plugin 'fact ' is de-initialized" << endl;
}

void run(void){

	int x;
	cout << "Please Enter x: ";
	cin >> x;
	int factX = fact( x );
	cout << x << "! = "<< factX<< endl;
	 
}

const char* can_do(void){
	return "Factorial of x ";
}

int fact(int x){
	if ( x <= 1 ){
		return 1;
	}
	if ( x == 2 ) {	
		return 2;
	}
	return x * fact( x - 1 );
}
