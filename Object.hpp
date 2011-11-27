#ifndef MHC8_OBJECT
#define MHC8_OBJECT

//#include "String.hpp"

namespace mhc8 {

class String;


class Object
{
 public:
	virtual int hashCode() const;
	//virtual const String& toString() const;
	virtual String toString() const;
};

} //end of namespace

#endif
