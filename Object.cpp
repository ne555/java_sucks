
#include "Object.hpp"
#include <typeinfo>
#include <sstream>
#include <iostream>
#include "String.hpp"

//using namespace mhc8;
using std::ostream;
using std::stringstream;

namespace mhc8{
//Object method definitions
int Object::hashCode() const {
	return (int)this;
	return 42;
}

//const String& Object::toString() const {
String Object::toString() const {
	stringstream ss;
	ss << typeid(*this).name() << '@' << this;
	return ss.str();
}


//operator definitions
/*ostream& operator<<(ostream &out, const Object &obj) {
	return out << obj.toString();
}*/

}
