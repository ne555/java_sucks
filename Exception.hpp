#ifndef MHC8_EXCEPTION
#define MHC8_EXCEPTION

#include <exception>
#include "Object.hpp"
#include "String.hpp"

namespace mhc8 {

using std::exception;


class Exception : public Object, public exception
{
 private:
	String msg;

 public:
	Exception();
	Exception(const String&);
	~Exception() throw();
	
	virtual Exception& operator=(const Exception&);
	virtual const char* what() const throw();
};

} //end of namespace

#endif
