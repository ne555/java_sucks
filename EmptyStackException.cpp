
#include "EmptyStackException.hpp"
#include "String.hpp"

using namespace mhc8;


//EmptyStackException constructor/destructor definitions
EmptyStackException::EmptyStackException() : Exception() {
}

EmptyStackException::EmptyStackException(const String &msg) : Exception(msg) {
}
