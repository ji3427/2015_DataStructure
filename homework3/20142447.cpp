#include <iostream>
#include <cstdlib>
#include <string>
#include "intchain.h"
#include "intnode.h"

using namespace std;

int main(void){
	string line;
	intchain ic;
	int num;
	intnode *temp;
	int num1,num2;
	while(getline(cin,line)){
		if(line[0]=='I'&&line[1]!='B'&&line[1]!='F'){
			for(int i=0;line[i]!='\0';i++){
				if(line[i]==' '){
					num1=atoi(&line.c_str()[i+1]);
					num=++i;
					break;
				}
			}
			for(int i=num;line[i]!='\0';i++){
				if(line[i]==' '){
					num2=atoi(&line.c_str()[i+1]);
					break;
				}
			}
			if(ic.serch(num1)==0){
				cout<<"error"<<endl;
			
			}
			else{
				ic.add(ic.serch(num1),num2);
				cout<<"done"<<endl;
			}
	}
	
		else if(line[0]=='I'&&line[1]=='B')
		{
			for(int i=0;line[i]!='\0';i++){
				if(line[i]==' '){
					num=atoi(&line.c_str()[i+1]);
					ic.add(num);
				}
			}
			cout<<"done"<<endl;
		}
		else if(line[0]=='I'&&line[1]=='F')
		{
			temp=ic.getfirst();
			ic.setfirst(0);
			for(int i=0;line[i]!='\0';i++){
				if(line[i]==' '){
					num=atoi(&line.c_str()[i+1]);
					ic.add(num);
				}
			}
			ic.connect(temp);
			cout<<"done"<<endl;
			
		}
		else if(line[0]=='D')
		{
			for(int i=0;line[i]!='\0';i++){
				if(line[i]==' '){
					num=atoi(&line.c_str()[i+1]);
					if(ic.serch(num)==0)
					{
						cout<<"error"<<endl;
					}
					else{
						ic.remove(num);
						cout<<"done"<<endl;
					}
				}
			
		}
	}
		else if(line[0]=='P'){
			if(ic.getfirst()==0){
				cout<<"error"<<endl;
			}
			else{	
				ic.print();
				cout<<endl;
		}
			
			
}
		else if(line[0]=='R'){
			if(ic.getfirst()==0){
				cout<<"error"<<endl;
			}
			else{
				ic.reverse();
				cout<<"done"<<endl;
			}
		}
}
}
		
	

