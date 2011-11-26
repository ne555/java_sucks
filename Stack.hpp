#ifndef MHC8_STACK
#define MHC8_STACK

namespace mhc8 {

template <typename T> class Stack
{	
 private:
	struct Node {
		T element;
		Node *next;
	} *top;

 public:
	Stack();
	Stack(const Stack&);
	virtual ~Stack();
	
	virtual bool empty() const;
	virtual T peak() const;
	virtual T pop();
	virtual void push(const T&);
};




} //end of namespace

#endif