#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack(int stackCapcity){
	capacity=stackCapcity;
	stack=new char[capacity];
	top=-1;
}

bool Stack::IsEmpty(){
	return top==-1;
}

char Stack::Top(){
	if(IsEmpty())throw "Stack is empty";
	return stack[top];
}

void Stack::Push(char item){
	stack[++top]=item;
}

void Stack::Pop(){
	if(IsEmpty())throw "Stack is empty";
	top--;
}

