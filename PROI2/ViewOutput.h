#include <string>
#pragma once
class ViewOutput
{
public:
	ViewOutput();
	~ViewOutput();
	void saveDataToFile(std::string message, int *pinPosition);
	void showDataToConsole(std::string message);
};

