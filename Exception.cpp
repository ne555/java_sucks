
#include "Exception.hpp"
#include "String.hpp"

using namespace mhc8;


//Exception constructor/destructor definitions
Exception::Exception() : msg("") {
}

Exception::Exception(const String &msg) : msg(msg) {
}


//Exception operator definitions
Exception& Exception::operator=(const Exception &e) {
	msg = e.msg;
}


//Exception method definitions
const char* Exception::what() const {
	return msg.c_str();
}
