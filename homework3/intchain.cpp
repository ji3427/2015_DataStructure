#include <iostream>
#include "intchain.h"
#include "intnode.h"

using namespace std;

intchain::intchain(){
	first=0;
	
}
void intchain::add(intnode*x,int num){
	if(first)
		x->next=new intnode(num,x->next);
}

void intchain::add(int num){
	if(first){
		intnode*temp=first;
		for(;temp->next!=0;temp=temp->next);
		temp->next=new intnode(num,0);
	}
	
	else
	first=new intnode(num,0);
}

void intchain::connect(intnode*x){
	intnode*temp=first;
	for(;temp->next!=0;temp=temp->next);
	temp->next=x;
}


intnode* intchain::serch(int num){
	if(first){
		intnode*temp=first;
		for(;temp->next!=0;temp=temp->next){
			if(temp->num==num){
				return temp;
			}
		}
		if(temp->next==0){
			return 0;
		}
	}
	else
		return 0;
	
}
void intchain::remove(int num){
	intnode *temp1=first;
	intnode * temp2=first;
	for(;temp2->next!=0;temp2=temp2->next);
	if(serch(num)==first){
		first=first->next;
	}
	else if(serch(num)==temp2){
		for(;temp1->next!=temp2;temp1=temp1->next);
		temp1->next=0;
	}
	else{
	for(;temp1->next!=serch(num);temp1=temp1->next);
	temp1->next=serch(num)->next;
}
}

intnode* intchain::getfirst(){
	return first;
}

void intchain::setfirst(intnode * temp){
	first=temp;
}

void intchain::print(){
	intnode*temp=first;
	cout<<first->num<<' ';
	temp=temp->next;
	for(;temp->next!=0;temp=temp->next){
			
		cout<<temp->num<<' ';
	}
	cout<<temp->num;
	}
	


void intchain::reverse(){
	intnode * current=first, * previous = 0;
	while(current){
		intnode* a = previous;
		previous=current;
		current=current->next;
		previous->next=a;
	}
	first=previous;
}
	
	
	


