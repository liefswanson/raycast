#include "ArgParse.hpp"

ArgParse::ArgParse(int argc, char* argv[]) {
	args = std::vector<std::string>(argc);

	for(int i = 0; i < argc; ++i) {
		args.push_back(std::string(argv[i]));
	}
}

ArgParse::~ArgParse(){}

bool
ArgParse::isSet(const std::string& arg) {
	for(auto &current : args) {
		if (current == arg) {
			return true;
		}
	}
	return false;
}

std::string
ArgParse::getValue(const std::string& arg) {
	auto ret = false;
	for(auto &current : args) {
		if (ret) {
			// check that the next value string after the flag i want is not another flag
			if (*current.begin() != '-' &&
				*current.begin() != '+'){
				return current;
			} else {
				break;
			}
		}
		if (current == arg) {
			ret = true;
		}
	}
	return "";
}
