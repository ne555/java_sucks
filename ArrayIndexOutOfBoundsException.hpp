#ifndef MHC8_ARRAYINDEXOUTOFBOUNDSEXCEPTION
#define MHC8_ARRAYINDEXOUTOFBOUNDSEXCEPTION

#include "IndexOutOfBoundsException.hpp"

namespace mhc8 {

class String;


class ArrayIndexOutOfBoundsException : public IndexOutOfBoundsException
{
 public:
	ArrayIndexOutOfBoundsException();
	ArrayIndexOutOfBoundsException(const String&);
};

} //end of namespace

#endif