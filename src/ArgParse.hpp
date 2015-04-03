#pragma once
#include <vector>
#include <string>

class ArgParse {
public:
	ArgParse (int argc, char* argv[]);
	~ArgParse();

	std::string getValue(const std::string& arg);
	bool        isSet   (const std::string& arg);
	
private:
	std::vector<std::string> args;
};

