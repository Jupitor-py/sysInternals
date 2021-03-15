#include <windows.h>
#include <iostream>
#include <string>

HINSTANCE executeShell(LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, INT nShowCmd)
{
	return ShellExecuteA(
		NULL,
		lpOperation,
		lpFile,
		lpParameters,
		NULL,
		nShowCmd
	);
}

int main(uint16_t argc, char* argv[])
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	if (executeShell("open", std::string(argv[1]).c_str(), std::string(argv[2]).c_str(), SW_HIDE) <= (HINSTANCE)33)
	{
		MessageBoxA(NULL, "Failed: To Execute", "Error", MB_ICONERROR);
	}

	ExitProcess(ERROR_SUCCESS);
}