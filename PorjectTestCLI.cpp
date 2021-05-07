// PorjectTestCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include "WinHWNDPrinter.h"
#include "Displays.h";
#include "ProcessInfo.h"
#include "AppManager.h"
#include <iostream>


using std::wcout;
using std::endl;


int main()
{
	//WinHWNDPrinter::PrintHWNDInfo();
	wcout << L"################################################################" << endl;
	wcout << L"################################################################" << endl;
	wcout << L"################################################################" << endl;
	wcout << L"################################################################" << endl;
	wcout << L"################################################################" << endl;
	Displays::Initialize();
	AppManager::Initialize();
	//AppManager::PrintWindowedApps();
	wcout << Displays::ToString() << endl;
	AppManager::PrintProfiles();
	//AppManager::PrintSizeOfWindowedApps();
}