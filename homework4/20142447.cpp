#include <iostream>
#include <cstdlib>
#include <string>
#include "MaxHeap.h"

using namespace std;

int main(void){
	string line;
	MaxHeap mh;
	int num1;

	
	while(getline(cin,line)){
		if(line[0]=='I'){
			num1=atoi(&line.c_str()[2]);
			mh.push(num1);
			cout<<"done"<<endl;
		}
		else if(line[0]=='D'&&line[1]!=' '){
			if(mh.get_heapSize()==0){
				cout<<"error"<<endl;
			}
			else{
			mh.pop();
			cout<<"done"<<endl;
		}
		}
		else if(line[0]=='T'&&line[1]!=' '){
			if(mh.get_heapSize()==0){
				cout<<"error"<<endl;
			}
			else{
				cout<<mh.top()<<endl;
			}
		}
		else if(line[0]=='P'){
			if(mh.get_heapSize()==0){
				cout<<"error"<<endl;
			}
			else{
				mh.print();
			}
			
		}
		else if(line[0]=='T'&&line[1]==' '){
			num1=atoi(&line.c_str()[2]);
			if(mh.get_heapSize()<num1){
				cout<<"error"<<endl;
			}
			else{
				cout<<mh.top(num1)<<endl;
			}
			
			
		}
		else if(line[0]=='D'&&line[1]==' '){
			num1=atoi(&line.c_str()[2]);
			if(mh.get_heapSize()<num1){
				cout<<"error"<<endl;
			}
			else{
				mh.pop(num1);
				cout<<"done"<<endl;
			}
			
		}
	}
	
}
