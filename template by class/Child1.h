#pragma once
#include <iostream>
#include <string>
#include <any>
#include "Base.h"

using namespace std;

template<class T1, class T2, class T3, class T4>
class Child1 : public Base<T1, T2>{
private:
	void parent_print_all() {
		Base<T1, T2>::print_all();
	}

protected:
	T3 variable3;
	T4 variable4;
	vector<any> array;
	string sec_print_all(vector<any> array);

public:
	Child1(T1 var1, T2 var2, T3 var3, T4 var4);
	Child1();
	inline void print_all() {
		parent_print_all();
		cout << sec_print_all(array) << endl;
	}

};


template<class T1, class T2, class T3, class T4>
inline string Child1<T1, T2, T3, T4>::sec_print_all(vector<any> array){
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
	return result;
}

template<class T1, class T2, class T3, class T4>
inline Child1<T1, T2, T3, T4>::Child1(T1 var1, T2 var2, T3 var3, T4 var4) : Base<T1, T2>(var1, var2), variable3{ var3 }, variable4{ var4 }, array{ var3, var4 }  {

}

template<class T1, class T2, class T3, class T4>
inline Child1<T1, T2, T3, T4>::Child1() 
	: Base<T1, T2>(), variable3{}, variable4{}
{}
