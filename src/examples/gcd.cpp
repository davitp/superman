#include <iostream> 
#include "protocol.h"
using namespace std;


void init(void){
	cout << "Plugin 'GCD' is initialized" << endl;
}

void destroy(void){
	cout << "Plugin 'GCD ' is de-initialized" << endl;
}

void run(void){

	int x,y;
	cout << "Please Enter x: ";
	cin >> x;
	cout << "Please Enter y: ";
	cin >> y;

	while ( x != y ) {
		if ( x > y ){
	  	  x = x - y;
		}
		else{
	  	  y = y - x;
		}
	}
	cout << "Greatest common divisor of x and y is "<< x << endl;
	 
}

const char* can_do(void){
	return "Greatest common divisor of x and y";
}

