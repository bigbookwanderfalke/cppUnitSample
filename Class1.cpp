#include "Class1.h"
#include <iostream>
using namespace std;

int Class1::func(int x)
{
	return s_func(x);
}

int Class1::s_func(int y)
{
	return y + 1;
}

