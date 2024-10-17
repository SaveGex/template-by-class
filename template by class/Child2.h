#pragma once
#include "Base.h"
#include "Child1.h"
#include <iostream>
#include <string>
#include <any>

using namespace std;

template<class T1, class T2, class T3, class T4, class T5, class T6>
class Child2 : private Child1<T1, T2, T3, T4>{
private:
	T5 variable5;
	T6 variable6;
	vector<any> array;

	string sec_print_all(vector<any> array);
public:
	Child2(T1 var1, T2 var2, T3 var3, T4 var4, T5 var5, T6 var6);
	Child2();
	void print_all() {
		Child1<T1, T2, T3, T4>::print_all();
		cout << "\033[F" << sec_print_all(array);//Cool gizmo
	}
};

template<class T1, class T2, class T3, class T4, class T5, class T6>
inline string Child2<T1, T2, T3, T4, T5, T6>::sec_print_all(vector<any> array) {
	string result;
	for (int i = 0; i < array.size(); i++) {
		if (array[i].has_value() && array[i].type() == typeid(int)) {
			result.append(to_string(any_cast<int>(array[i])) + " ");
		}
		else if (array[i].has_value() && array[i].type() == typeid(short)) {
			result.append(to_string(any_cast<short>(array[i])) + " ");
		}
		else if (array[i].has_value() && array[i].type() == typeid(double)) {
			result.append(to_string(any_cast<double>(array[i])) + " ");
		}
		else if (array[i].has_value() && array[i].type() == typeid(float)) {
			result.append(to_string(any_cast<float>(array[i])) + " ");
		}
		else if (array[i].has_value() && array[i].type() == typeid(bool)) {
			result.append((any_cast<bool>(array[i]) ? "true" : "false") + string(" "));
		}
		else if (array[i].has_value() && array[i].type() == typeid(const char*)) {
			result.append(any_cast<const char*>(array[i]) + string(" "));
		}
		else if (array[i].has_value() && array[i].type() == typeid(char*)) {
			result.append(any_cast<char*>(array[i]) + string(" "));
		}
		else if (array[i].has_value() && array[i].type() == typeid(string)) {
			result.append(any_cast<string>(array[i]) + " ");
		}
	}
	//cpu /*what is that?*/
	return result;
}

template<class T1, class T2, class T3, class T4, class T5, class T6>
inline Child2<T1, T2, T3, T4, T5, T6>::Child2(T1 var1, T2 var2, T3 var3, T4 var4, T5 var5, T6 var6) 
	: Child1<T1, T2, T3,T4>(var1, var2, var3, var4), variable5{var5}, variable6{ var6 }, array{var5, var6}
{
}

template<class T1, class T2, class T3, class T4, class T5, class T6>
inline Child2<T1, T2, T3, T4, T5, T6>::Child2() 
	: Child1<T1, T2, T3, T4>(), variable5{}, variable6{}, array{}
{
}
