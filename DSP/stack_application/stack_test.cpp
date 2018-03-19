// stack_test.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <stdio.h>
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "StackApplication.h"

using namespace std;

void TestArrayStack();
void TestLinkedStack();

int main()
{

	TestArrayStack();

    TestLinkedStack();

	cout<<endl;
	
	cout<<"Test if the symbol sequence is balance"<<endl;
    cout<<"==============Begin==================="<<endl;

	char e1[16]={'{','[','(',')','(','{','[',']','}',')',']','}'};
	char e2[16]={'{','[','(','(',')','(',']','}',')',']','}'};

	cout<<"Is "<<e1<< " Balance? "<<endl;
	cout<<"The result is "<<isBalance(e1)<<endl<<endl;

	cout<<"Is "<<e2<< " Balance? "<<endl;
	cout<<"The result is "<<isBalance(e2)<<endl;

    cout<<"==============End==================="<<endl<<endl;


	cout<<"Test Expression Evaluation"<<endl;
	cout<<"==============Begin==================="<<endl;

	char e3[]="5+7*3-(6*2+1)/10";
	//char e3[]="1.25*3.6+8000.9/15.2*(123-456*789)";

	cout<<"Expression Evaluation"<<endl;
	cout<<endl<<e3<< " = "<<ExpressionEvaluation(e3)<<endl;

	 cout<<"==============End==================="<<endl;

	cout<<endl;
	system("pause");

	return 0;
}

void TestArrayStack()
{
	cout<<"========================="<<endl;
	cout<<"Array based stack"<<endl;
	cout<<"========================="<<endl;
	ArrayStack<char> c_stack;

	cout<<"Stack Push"<<endl;
	c_stack.push('H');
    cout<<"Top of the stack is:  ";
	cout<<c_stack.top()<<endl;


	cout<<"Stack Push"<<endl;
	c_stack.push('e');

	cout<<"Top of the stack is:  ";
	cout<<c_stack.top()<<endl;

	cout<<"Is stack empty?  ";
	cout<<c_stack.isEmpty()<<endl;

	cout<<"Stack Pop  ";
	cout<<c_stack.pop()<<endl;

    cout<<"Is stack empty?  ";
	cout<<c_stack.isEmpty()<<endl;

	cout<<"Stack Pop  ";
	cout<<c_stack.pop()<<endl;

    cout<<"Is stack empty?  ";
	cout<<c_stack.isEmpty()<<endl;
};

void TestLinkedStack()
{
	cout<<"========================="<<endl;
	cout<<"Linked List based stack"<<endl;
	cout<<"========================="<<endl;
	LinkStack<int> i_stack;
	cout<<"Stack Push"<<endl;
    i_stack.push(1);

	cout<<"Top of the stack is:  ";
    cout<<i_stack.top()<<endl;

	cout<<"Stack Push"<<endl;
	i_stack.push(2);

	cout<<"Top of the stack is:  ";
    cout<<i_stack.top()<<endl;

	cout<<"Stack Pop  ";
	cout<<i_stack.pop()<<endl;

	cout<<"Top of the stack is:  ";
	cout<<i_stack.top()<<endl;

	cout<<"Is stack empty?  ";
	cout<<i_stack.isEmpty()<<endl;

	cout<<"Stack Pop  ";
	cout<<i_stack.pop()<<endl;

	cout<<"Is stack empty?  ";
	cout<<i_stack.isEmpty()<<endl;
};