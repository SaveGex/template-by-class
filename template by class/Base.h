#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <any>

using namespace std;

template <class T1, class T2>
class Base{
private:

	//class Manager {
	//	Manager() {
	//		initialize_array();
	//	}
	//};
	//Manager manager;

protected:
	T1 variable1;
	T2 variable2;
	vector<any> array;

	//inline void initialize_array() {
	//	array.push_back(variable1);
	//	array.push_back(variable2);
	//}
	//i understand what i can make  |
public:							 //\|/
	Base(T1 var1, T2 var2);// : array{var1, var2} but if var1 its different type of var2, can use just "any". 
	Base();                //So it's  not as interesting as make class inside other class which call when create general class

	//~Base(); // idk this construction need the destructor or doesn't need. And a compiler work a bit strange(But the problem is me.). 
	// He think what the type "string" it is a pointer and tryes to delete him but he can't do it.
	// But its working
	void print_all();
	
};



// Constructor Definitions
template<class T1, class T2>
Base<T1, T2>::Base(T1 var1, T2 var2) : variable1{ var1 }, variable2{ var2 }, array{var1, var2}
{}

template<class T1, class T2>
Base<T1, T2>::Base() : variable1{}, variable2{} {}

//template<class T1, class T2>
//Base<T1, T2>::~Base() {
//	string result = "\nwas deleted: ";
//	for (auto &item : array) {
//		// Check for int pointer
//		if (item.type() == typeid(int*)) {
//			int* ptr = any_cast<int*>(item);
//			if (ptr) {
//				result.append(to_string(*ptr) + " ");
//				delete ptr;  // Only delete if it's a valid pointer
//			}
//		}
//		// Handle other types accordingly
//		else if (item.type() == typeid(short)) {
//			result.append(to_string(any_cast<short>(item)) + " ");
//		}
//		else if (item.type() == typeid(double)) {
//			result.append(to_string(any_cast<double>(item)) + " ");
//		}
//		else if (item.type() == typeid(float)) {
//			result.append(to_string(any_cast<float>(item)) + " ");
//		}
//		else if (item.type() == typeid(bool)) {
//			result.append((any_cast<bool>(item) ? "true" : "false") + string(" "));
//		}
//		else if (item.type() == typeid(const char*)) {
//			result.append(any_cast<const char*>(item) + string(" "));
//		}
//		else if (item.type() == typeid(char*)) {
//			char* ptr = any_cast<char*>(item);
//			if (ptr) {
//				result.append(string(ptr) + " ");  // Correctly create std::string
//			}
//		}
//	}
//	cout << result;
//
//}

template<class T1, class T2>
inline void Base<T1, T2>::print_all() {
	string result;
	for (int i = 0; i < array.size(); i++) {
		if (array[i].type() == typeid(int)) {
			result.append(to_string(any_cast<int>(array[i])) + " ");
		}
		else if (array[i].type() == typeid(short)) {
			result.append(to_string(any_cast<short>(array[i])) + " ");
		}
		else if (array[i].type() == typeid(double)) {
			result.append(to_string(any_cast<double>(array[i])) + " ");
		}
		else if (array[i].type() == typeid(float)) {
			result.append(to_string(any_cast<float>(array[i])) + " ");
		}
		else if (array[i].type() == typeid(bool)) {
			result.append((any_cast<bool>(array[i]) ? "true" : "false") + string(" "));
		}
		else if (array[i].type() == typeid(const char*)) {
			result.append(any_cast<const char*>(array[i]) + string(" "));
		}
		else if (array[i].type() == typeid(char*)) {
			result.append(any_cast<char*>(array[i]) + string(" "));
		}
		else if (array[i].type() == typeid(string)) {
			result.append(any_cast<string>(array[i]) + " ");
		}
	}
	//cpu /*what is that?*/
	cout << result;
}
