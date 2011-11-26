#ifndef MHC8_EMPTYSTACKEXCEPTION
#define MHC8_EMPTYSTACKEXCEPTION

#include "Exception.hpp"

namespace mhc8 {

class String;


class EmptyStackException : public Exception
{
 public:
	EmptyStackException();
	EmptyStackException(const String&);
};

} //end of namespace

#endif