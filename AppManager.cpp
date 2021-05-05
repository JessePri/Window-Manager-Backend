#include "AppManager.h"
#include "Application.h"
#include <Windows.h>
#include <Psapi.h>
#include <vector>
#include <string>
#include <fstream>

using std::wstring;
using std::wifstream;
using std::vector;
using std::getline;

Application::WinMap AppManager::windowedApps;

void AppManager::GetAllWindowedApplications() {
	windowedApps.clear();
	LPARAM ignored = 0;
	EnumWindows(WindowConstructor, ignored);
}

BOOL CALLBACK AppManager::WindowConstructor(_In_ HWND hwnd, LPARAM IGNORED) {
	Application app(hwnd);
	if (!app.IsValid()) {
		return true;
	}
	auto iter = windowedApps.find(app.GetWindowModulePath());
	if (iter == windowedApps.end()) {
		vector<Application> temp;
		temp.push_back(std::move(app));
		windowedApps.emplace(app.GetWindowModulePath(),std::move(temp));
	} else {
		iter->second.push_back(std::move(app));
	}
	return true;
}

const Application::WinMap& AppManager::GetWindowedApps() {
	return windowedApps;
}

void AppManager::ReadProfilesConstrained(const char* filePath) {
	wifstream input(filePath);
	if (input.is_open()) {
		while (!input.eof()) {
			profiles.emplace_back(input);
		}
	} else {
		// Do some logging
	}
}


AppManager::Profile::Profile(wifstream& input, bool constrained) {
	// The boolean will be used when the Advanced Profiles are implemented
	// For now it should be ignored
	ReadProfileConstrained(input);
}

void AppManager::Profile::ReadProfileConstrained(wifstream& input) {
	wstring temp;
	while (getline(input, temp)) {

	}
}