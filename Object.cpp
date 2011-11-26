
#include "Object.hpp"
#include <typeinfo>
#include <sstream>
#include "String.hpp"

using namespace mhc8;
using std::ostream;
using std::stringstream;


//Object method definitions
int Object::hashCode() const {
	return (int)this;
}

String Object::toString() const {
	stringstream ss;
	ss << typeid(*this).name() << '@' << this;
	return ss.str();
}


//operator definitions
ostream operator<<(ostream &out, const Object &obj) {
	return out << obj.toString();
}
