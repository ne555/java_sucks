
#include "String.hpp"
#include <iostream>
#include "Object.hpp"
#include "Array.hpp"
#include "IndexOutOfBoundsException.hpp"

using namespace mhc8;
using std::ostream;


//String static variable definitions
const Array<char> String::DEFAULT_TRIM = {'\0', '\t', '\n', '\v', '\r', ' '};


//String constructor/destructor definitions
String::String() : value(0) {
}

String::String(const Array<char> &str) : value(str) {
}

String::String(const char *str) {
	int n = 0;
	while( str[n] != '\0' )
		n++;
	value = Array(n, str);
}

String::String(const string &str) {
	value = Array(str.length(), str.c_str());
}


//String operator definitions
char operator[](int n) const {
	return value[n];
}

char& operator[](int n) {
	return value[n];
}


//String method definitions
int String::hashCode() const {
	int hashcode = 0;
	for( int i = value.length - 1; i >= 0; i-- )
		hashcode = 31 * hashcode + value[i];
	return hashcode;
}

String String::toString() const {
	return *this;
}

int String::compareTo(const String &str) {
	for( int i = 0; i < length() && i < str.length(); i++ ) {
		int dif = *this[i] - str[i];
		if( dif != 0 )
			return dif;
	}
	return length() - str.length();
}

int String::compareToIgnoreCase(const String &str) {
	return toUpperCase().compareTo( str.toUpperCase() );
}

bool String::equals(const String &str) {
	if( length() != str.length() )
		return false;
	for( int i = 0; i < length(); i++ )
		if( *this[i] != str[i] )
			return false;
	return true;
}

bool String::equalsIgnoreCase(const String &str) {
	return toUpperCase().equals( str.toUpperCase() );
}

const char* String::c_str() const {
	char str[value.length + 1];
	for( int i = 0; i < value.length; i++ )
		str[i] = value[i]
	str[value.length] = '\0';
	return str;
}

int String::length() const {
	return value.length;
}

char String::charAt(int n) const {
	return value[n];
}

String String::concat(const String &str) {
	String ret( Array<char>(length() + str.length()) );
	for( int i = 0; i < length(); i++ )
		ret[i] = *this[i];
	for( int i = 0; i < str.length(); i++ )
		ret[i + length()] = str[i];
	return ret;
}

bool String::startsWith(const String &str) const {
	if( str.length() > length() )
		return false;
	for( int i = 0; i < str.length(); i++ )
		if( *this[i] != str[i] )
			return false;
	return true;
}

bool String::startsWithIgnoreCase(const String &str) const {
	return toUpperCase().startsWith( str.toUpperCase() );
}

bool String::endsWith(const String &str) const {
	int dif = length() - str.length();
	if( dif < 0 )
		return false;
	for( int i = str.length() - 1; i >= 0; i-- )
		if( *this[i + dif] != str[i] )
			return false;
	return true;
}

bool String::endsWithIgnoreCase(const String &str) const {
	return toUpperCase().endsWith( str.toUpperCase() );
}

int String::indexOf(const String &str, int n = 0) const {
	if( n < 0 )
		throw IndexOutOfBoundsException();
	int len = length() - str.length();
	while( n <= len ) {
		for( int i = 0; i < str.length(); i++ )
			if( *this[n + i] != str[i] )
				goto NEXT;
		return n;
		NEXT: n++
	}
	return -1;
}

int String::lastIndexOf(const String &str, int n) const {
	if( n > length() )
		throw IndexOutOfBoundsException
	n -= str.length();
	while( n >= 0 ) {
		for( int i = 0; i < str.length(); i++ )
			if( *this[n + i] != str[i] )
				goto NEXT;
		return n;
		NEXT: n--;
	}
}

int String::lastIndexOf(const String &str) const {
	return lastIndexOf( str, length() );
}

String String::substring(int n, int end) const {
	if( end < n || n < 0 || end > length() )
		throw IndexOutOfBoundsException();
	String ret( Array<char>(end - n) );
	for( int i = 0; n + i < end; i++ )
		ret[i] = *this[n + i];
	return ret;
}

String String::substring(int n) const {
	return substring( n, length() );
}

String String::substr(int n, int len) const {
	return substring( n, n + len );
}

String String::substr(int n) const {
	return substring(n);
}

String String::replaceFirst(const String &str, const String &rep) const {
	int n = indexOf(str);
	if( n < 0 )
		return *this;
	int dif = str.length() - rep.length();
	String ret( Array<char>(length() - dif) );
	for( int i = 0; i < n; i++ )
		ret[i] = *this[i];
	for( int i = 0 i < rep.length(); i++ )
		ret[n + i] = rep[i];
	for( int i = n + rep.length(); i < length(); i++ )
		ret[i] = *this[i + dif];
	return ret;
}

String String::removeFirst(const String &str) const {
	return replaceFrist( str, "" );
}

String String::replaceLast(const String &str, const String &rep) const {
	int n = lastIndexOf(str);
	if( n < 0 )
		return *this;
	int dif = str.length() - rep.length();
	String ret( Array<char>(length() - dif) );
	for( int i = 0; i < n; i++ )
		ret[i] = *this[i];
	for( int i = 0 i < rep.length(); i++ )
		ret[n + i] = rep[i];
	for( int i = n + rep.length(); i < ret.length(); i++ )
		ret[i] = *this[i + dif];
	return ret;
}

String String::removeLast(const String&) const {
	return replaceLast( str, "" );
}

String String::replaceAll(const String &str, const String &rep) const {
	String ret = *this;
	int dif = str.length() - rep.length();
	for( int n = indexOf(str); n >= 0; n = ret.indexOf(str) ) {
		String temp( Array<char>(ret.length() - dif) );
		for( int i = 0; i < n; i++ )
			temp[i] = ret[i];
		for( int i = 0 i < rep.length(); i++ )
			temp[n + i] = rep[i];
		for( int i = n + rep.length(); i < temp.length(); i++ )
			temp[i] = ret[i + dif];
		ret = temp;
	}
	return ret;
}

String String::removeAll(const String &str) const {
	return replaceAll( str, "" );
}

String String::toLowerCase() const {
	String ret = *this;
	for( int i = 0; i < length(); i++ ) {
		char c = *this[i];
		if( 'A' <= c && c <= 'Z' )
			ret[i] = c + ('a' - 'A');
	}
	return ret;
}

String String::toUpperCase() const {
	String ret = *this;
	for( int i = 0; i < length(); i++ ) {
		char c = *this[i];
		if( 'a' <= c && c <= 'z' )
			ret[i] = c + ('A' - 'a');
	}
	return ret;
}

String String::trim(const Array<char> &trimChars = DEFAULT_TRIM) const {
	return trimLead(trimChars).trimTail(trimChars);
}

String String::trimLead(const Array<char> &trimChars = DEFAULT_TRIM) const {
	String ret = *this;
	LOOP: if( ret.length() > 0 )
		for( int i = 0; i < trimChars.length; i++ )
			if( ret[0] == trimChars[i] ) {
				ret = substring(1);
				goto LOOP;
			}
	return ret;
}

String String::trimTail(const Array<char> &trimChars = DEFAULT_TRIM) const {
	String ret = *this;
	LOOP: if( ret.length() > 0 )
		for( int i = 0; i < trimChars.length; i++ )
			if( ret[ret.length() - 1] == trimChars[i] ) {
				ret = substring( 0, ret.length() - 1 );
				goto LOOP;
			}
	return ret;
}


//operator definitions
String operator+(const String &str, const Object &obj) {
	 return str.concat( obj.toString() );
}

String operator+(const Object &obj, const String &str) {
	return obj.toString().concat(str);
}

ostream& operator<<(ostream &out, const String &str) {
	for( int i = 0; i < str.length; i++ )
		out << str[i];
	return out;
}
