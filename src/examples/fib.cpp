#include <iostream> 
#include "protocol.h"
using namespace std;
int nThFibonacci(int n);

void init(void){
	cout << "Plugin 'fibonacci' is initialized" << endl;
}

void destroy(void){
	cout << "Plugin 'fibonacci' is de-initialized" << endl;
}

void run(void){

	int n;
	cout << "Please Enter n: ";
	cin >> n;
	cout << n << "-th Fibonacci number = "<< nThFibonacci(n) << endl;
	 
}

const char* can_do(void){
	return "n-th fibonacci number";
}

int nThFibonacci(int n){
	if ( n < 3 ){
		return 1;
	}
	if ( n == 2 ) {	
		return 2;
	}
	return nThFibonacci( n - 1 ) + nThFibonacci( n - 2 );
}

