
#include "ArrayIndexOutOfBoundsException.hpp"
#include "String.hpp"

using namespace mhc8;


//ArrayIndexOutOfBoundsException constructor/destructor definitions
ArrayIndexOutOfBoundsException::ArrayIndexOutOfBoundsException() : IndexOutOfBoundsException() {
}

ArrayIndexOutOfBoundsException::ArrayIndexOutOfBoundsException(const String &msg) : IndexOutOfBoundsException(msg) {
}
