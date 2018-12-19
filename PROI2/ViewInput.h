#include <string>
#pragma once
class ViewInput
{
public:
	ViewInput();

	void getDataFromConsole(std::string *message, int *pinPosition);
	void getDataFromFile(std::string *message, int *pinPosition);
};

