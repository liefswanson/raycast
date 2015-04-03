#pragma once
#include <vector>
#include <string>

class argParse {
public:
	argParse (int argc, char* argv[]);
	~argParse();

	std::string getValue(const std::string& arg);
	bool        isSet   (const std::string& arg);
	
private:
	std::vector<std::string> args;
};

