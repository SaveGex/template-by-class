#pragma once
#include "Child1.h"
#include <iostream>
#include <string>
#include <any>

using namespace std;

template<class T1, class T2, class T3, class T4, class T5, class T6>
class Child2 : private Child1<T3, T4>{
private:

public:

};

