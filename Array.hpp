#ifndef MHC8_ARRAY
#define MHC8_ARRAY

#include "Object.hpp"

namespace mhc8 {

template <typename T> class Array : public Object
{
 private:
	T *values;
	int count;

 public:
	const int &length;
	
	Array(int);
	Array(int, T*);
	Array(const Array&);
	virtual ~Array();
	
	virtual Array<T>& operator=(const Array<T>&);
	virtual const T& operator[](int) const;
	virtual T& operator[](int);
};
}



#include "ArrayIndexOutOfBoundsException.hpp"
namespace mhc8{

//mhc8::Array<T> constructors/destructors
template <typename T> Array<T>::Array(int length) : count(length), length(count) {
	values = new T[length];
}

template <typename T> Array<T>::Array(int length, T *values) : count(length), length(count) {
	this->values = new T[length];
	for( int i = 0; i < length; i++ )
		this->values[i] = values[i];
}

template <typename T> Array<T>::Array(const Array<T> &array) : count(array.length), length(count) {
	values = new T[length];
	for( int i = 0; i < length; i++ )
		values[i] = array.values[i];
}

template <typename T> Array<T>::~Array() {
	delete[] values;
}


//mhc8::Array<T> operator definitions
template <typename T> Array<T>& Array<T>::operator=(const Array<T> &array) {
	delete[] values;
	count = array.length;
	values = new T[length];
	for( int i = 0; i < length; i++ )
		values[i] = array.values[i];
	return *this;
}

template <typename T> const T& Array<T>::operator[](int n) const {
	if( n < 0 || n >= length )
		throw ArrayIndexOutOfBoundsException();
	return values[n];
}

template <typename T> T& Array<T>::operator[](int n) {
	if( n < 0 || n >= length )
		throw ArrayIndexOutOfBoundsException();
	return values[n];
}

} //end of namespace

#endif

