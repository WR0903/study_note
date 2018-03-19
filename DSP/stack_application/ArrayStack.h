#ifndef ARRAY_STACK
#define ARRAY_STACK

const int SIZE=1024;

template <class T>
class ArrayStack
{
private:
	T buf[SIZE];
	int index;

public:

	ArrayStack():index(-1){};

	void push(T a)
	{
		buf[++index]=a;
	};

	T pop()
	{
		return buf[index--];
	};

	T top()
	{
		return buf[index];
	};

	bool isEmpty(){return -1==index;}

	bool isFull(){return (SIZE-1)==index;}
};

#endif