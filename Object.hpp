#ifndef MHC8_OBJECT
#define MHC8_OBJECT

namespace mhc8 {

class String;


class Object
{
 public:
	virtual int hashCode() const;
	virtual String toString() const;
};

} //end of namespace

#endif
