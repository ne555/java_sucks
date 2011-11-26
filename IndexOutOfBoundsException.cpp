
#include "IndexOutOfBoundsException.hpp"
#include "String.hpp"

using namespace mhc8;


//IndexOutOfBoundsException constructor/destructor definitions
IndexOutOfBoundsException::IndexOutOfBoundsException() : Exception() {
}

IndexOutOfBoundsException::IndexOutOfBoundsException(const String &msg) : Exception(msg) {
}
