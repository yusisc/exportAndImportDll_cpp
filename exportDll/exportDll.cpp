//Exporting from a DLL Using __declspec(dllexport) | Microsoft Docs
//https://docs.microsoft.com/en-us/cpp/build/exporting-from-a-dll-using-declspec-dllexport?view=msvc-170
#include <iostream>

#define DLLEXPORT extern "C" __declspec(dllexport)

DLLEXPORT int my_add(int aa, int bb)
{
	return aa + bb;
}

int main()
{
	std::cout << my_add(1, 2) << std::endl;
	return 0;
}