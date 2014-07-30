#include <iostream> 
#include <math.h>
#include "protocol.h"
using namespace std;


void init(void){
	cout << "Plugin 'prime' is initialized" << endl;
}

void destroy(void){
	cout << "Plugin 'prime' is de-initialized" << endl;
}

void run(void){
	int x;
	cout << "Please Enter x: ";
	cin >> x;

	int i = 2;
 
	if (x == 2 || x == 1) {
		cout << x <<" is a prime number" << endl;
		return;	
	}
 
	int sqrtX = ( int )sqrt ( x );
	while (i <= sqrtX) {
		if (x % i == 0) {
			cout << x <<" is not a prime number" << endl;
			return;	
		}
		i++;
	}
 
	cout << x <<" is a prime number" << endl;
	 
}

const char* can_do(void){
	return "is prime number?";
}



