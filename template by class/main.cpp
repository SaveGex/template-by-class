#include <iostream>
#include <string>
#include "Base.h"
#include "Child1.h"

using namespace std;

int main() {
	const char* originalString = "HELLO WORLD!!!"; 
	char* csp = new char[strlen(originalString) + 1]; 
	strcpy_s(csp, strlen(originalString) + 1, originalString); 

	Base<float, char*> base(12.23f, csp);
	base.print_all();


	
	Child1<float, char*, string, const char*> c1(32.123f, csp, string("Tutututrurututu"), originalString);
	c1.print_all();
	delete[] csp;



	return 0;
}