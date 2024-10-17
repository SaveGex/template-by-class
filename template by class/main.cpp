#include <iostream>
#include <string>
#include "Base.h"
#include "Child1.h"
#include "Child2.h"

using namespace std;

int main() {
	const char* originalString = "HELLO WORLD!!!"; 
	char* csp = new char[strlen(originalString) + 1]; 
	strcpy_s(csp, strlen(originalString) + 1, originalString); 

	Base<float, char*> base(12.23f, csp);
	base.print_all();


	
	Child1<float, char*, string, const char*> c1(32.123f, csp, string("Sie sind das Essen und wir sind die Jager!"), originalString);
	c1.print_all();

	Child2<float, char*, string, const char*, const char*, bool> c2(321.123f, csp, string("And their words are like knives"), originalString, "Never let them get away", true);
	c2.print_all();
	//i took words of songs so it can be i bit strange
	delete[] csp;

	return 0;
}