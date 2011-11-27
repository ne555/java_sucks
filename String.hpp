#include "Array.hpp"
#ifndef MHC8_STRING
#define MHC8_STRING

#include <string>
#include "Object.hpp"
#include "Comparable.hpp"

namespace mhc8 {

using std::string;


class String : public Object, public Comparable<String>
{
 private:
	static const Array<char> DEFAULT_TRIM;
	
	Array<char> value;

 public:
	String();
	String(const Array<char>&);
	String(const char*);
	String(const string&);
	
	virtual char operator[](int) const;
	virtual char& operator[](int);
	
	virtual int hashCode() const;
	virtual String toString() const;
	virtual int compareTo(const String&) const;
	virtual int compareToIgnoreCase(const String&) const;
	virtual bool equals(const String&) const;
	virtual bool equalsIgnoreCase(const String&) const;
	virtual const char* c_str() const;
	virtual int length() const;
	virtual char charAt(int) const;
	virtual String concat(const String&) const;
	virtual bool startsWith(const String&) const;
	virtual bool startsWithIgnoreCase(const String&) const;
	virtual bool endsWith(const String&) const;
	virtual bool endsWithIgnoreCase(const String&) const;
	virtual int indexOf(const String&) const;
	virtual int indexOf(const String&, int) const;
	virtual int lastIndexOf(const String&) const;
	virtual int lastIndexOf(const String&, int) const;
	virtual String substring(int, int) const;
	virtual String substring(int) const;
	virtual String substr(int, int) const;
	virtual String substr(int) const;
	virtual String replaceFirst(const String&, const String&) const;
	virtual String removeFirst(const String&) const;
	virtual String replaceLast(const String&, const String&) const;
	virtual String removeLast(const String&) const;
	virtual String replaceAll(const String&, const String&) const;
	virtual String removeAll(const String&) const;
	//virtual Array<String> split(const String&) const;
	//virtual Array<String> split(const String&, int) const;
	virtual String toLowerCase() const;
	virtual String toUpperCase() const;
	virtual String trim(const Array<char>&) const;
	virtual String trim() const;
	virtual String trimLead(const Array<char>&) const;
	virtual String trimLead() const;
	virtual String trimTail(const Array<char>&) const;
	virtual String trimTail() const;
	//virtual String reverse() const;
	//virtual String concatCopies(int) const;
};

} //end of namespace

#endif
