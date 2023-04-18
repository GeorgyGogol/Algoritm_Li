// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


extern "C" {

	bool __declspec(dllexport) CreateField(int width, int height)
	{
		return false;
	}

	bool __declspec(dllexport) SaveField(const char* Path)
	{
		return false;
	}

	bool __declspec(dllexport) LoadField(const char* Path)
	{
		return false;
	}

	bool __declspec(dllexport) CalcField(int fromX, int fromY, int toX, int toY)
	{
		return false;
	}



}