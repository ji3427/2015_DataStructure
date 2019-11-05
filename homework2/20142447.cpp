#include <iostream>
#include "stack.h"



#define isnum(x) (x>='0' && x<='9') 

using namespace std;

int main(void){
    string line;
    char propmpt;
    int length;
    int i;
    while(getline(cin,line)) {
        length= (int)line.length();
        Stack s(length);
        i=0;
        if(line[0]=='+') {
            i++;
        }
        if(line[0]=='-') {
            cout<<line[0];
            i++;
        }
        s.Push('#'); 
        for(;i<length;i++) {
            propmpt=line[i];
            if(isnum(propmpt)){ 
                cout<<line[i]; 
            } else {
                if (i != 0) { 
                    if (isnum(line[i - 1]) && !isnum(line[i]) && line[i] != '(') { 
                        cout << " ";
                    }
                }
                if(propmpt=='+'||propmpt=='-') {
                    if(s.IsEmpty()){
                        s.Push(propmpt);
                    } else {
                        while(!s.IsEmpty() && (s.Top()=='+'||s.Top()=='-'||s.Top()=='*'||s.Top()=='/')) {
                            cout<<s.Top()<<" ";
                            s.Pop();
                        }
                        s.Push(propmpt);
                    }
                    
                }
                else if(!s.IsEmpty() && (propmpt=='*'||propmpt=='/')) {
                    if(s.IsEmpty()){
                        s.Push(propmpt);
                    } else {
                        while(s.Top()=='*'||s.Top()=='/') {
                            cout<<s.Top()<<" ";
                            s.Pop();
                        }
                        s.Push(propmpt);
                    }
                }
                else if(propmpt=='('){
                    if(s.IsEmpty()) {
                        s.Push(propmpt);
                    } else {
                        s.Push(propmpt);
                    }
                }
                else if(propmpt==')'){
                    while(s.Top()!='('){
                        cout<<s.Top()<<" ";
                        s.Pop();
                    }
                    s.Pop();
                }
                if((line[i] == '+'||line[i] == '-'||line[i] == '*'||line[i] == '/'||line[i] == '(') && line[i+1]=='+'){ //단항 스킵
                    i++;
                }
                if((line[i] == '+'||line[i] == '-'||line[i] == '*'||line[i] == '/'||line[i] == '(') && line[i+1]=='-'){//단항 스킵
                    cout<<"-";
                    i++;
                }
            }
        }
        if(s.Top() !='#'&&line[length-1]==')'){
			cout<<s.Top();
			s.Pop();
		}
        
  
		
        while(!s.IsEmpty()) {
            if(s.Top() != '#') 
            cout<< " " << s.Top();
            s.Pop();
        }
        cout<<endl;
    }
}
