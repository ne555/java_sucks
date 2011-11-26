#ifndef MHC8_COMPARABLE
#define MHC8_COMPARABLE

namespace mhc8 {

template <typename T> class Comparable
{
 public:
	virtual int compareTo(const T&) const = 0;
};

} //end of namespace

#endif