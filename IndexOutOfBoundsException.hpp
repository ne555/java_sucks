#ifndef MHC8_INDEXOUTOFBOUNDSEXCEPTION
#define MHC8_INDEXOUTOFBOUNDSEXCEPTION

#include "Exception.hpp"

namespace mhc8 {

class String;


class IndexOutOfBoundsException : public Exception
{
 public:
	IndexOutOfBoundsException();
	IndexOutOfBoundsException(const String&);
};

} //end of namespace

#endif