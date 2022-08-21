//c++ - How to reference a dll to Visual Studio without lib file - Stack Overflow
//https://stackoverflow.com/questions/31708832/how-to-reference-a-dll-to-visual-studio-without-lib-file
//
//LoadLibraryA function(libloaderapi.h) - Win32 apps | Microsoft Docs
//https ://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya?redirectedfrom=MSDN
//
//GetProcAddress function(libloaderapi.h) - Win32 apps | Microsoft Docs
//https ://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress?redirectedfrom=MSDN

#include <iostream>
#include <Windows.h>

namespace dllFunc
{
	// define the function types that export to the dll file, so that the new application could parse it as it is.
	extern "C" {
		typedef int(*type_my_add)(int aa, int bb);
	}
	// define the function entity, for further calling.
	type_my_add my_add;

	// module handle for the dll file.
	HMODULE hdl;

	// path to the dll file to be loaded.
	std::string dll_filename = "../x64/Debug/exportDll.exe";

	int load_dll()
	{
		hdl = LoadLibraryA(dll_filename.c_str());
		if (hdl)
		{
			dllFunc::my_add = reinterpret_cast<dllFunc::type_my_add>(GetProcAddress(hdl, "my_add"));
			if (!dllFunc::my_add)
			{
				printf("no function\n");
				return -1;
			}
			else
			{
				void;
			}
		}
		else
		{
			printf("no library\n");
			return -1;
		}

		return 0;
	}

	int release_dll()
	{
		FreeLibrary(hdl);
		return 0;
	}
}

int main()
{
	dllFunc::load_dll();

	printf_s("start ...\n");
	printf_s("%d\n", dllFunc::my_add(33, 44));

	dllFunc::release_dll();
	return 0;
}