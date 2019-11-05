#include <iostream>
#include "intnode.h"

using namespace std;

intnode::intnode(int num,intnode* next){
	this->num=num;
	this->next=next;
}
