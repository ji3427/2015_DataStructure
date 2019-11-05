#include <iostream>
#include <vector>


using namespace std;
	vector<string> lines;

int compare(string l1,string l2){
	return l1.compare(l2);
}
void swap(int i,int j){
		string temp;
		temp=lines[j];
		lines[j]=lines[i];
		lines[i]=temp;
}



/*
void Qsort(int left,int right){
	string pivot,temp;
	int i=left,j=left;
	if(left<right){
		pivot=lines[left];
		do
		{
			if(lines[j+1].compare(pivot)<0){
				swap(i+1,j+1);
				i++;
			}
			if(j+1==right){
				break;
			}
			j++;
		}while(1);
		temp=lines[i];
		lines[i]=pivot;
		lines[left]=temp;
		Qsort(left,i-1);
		Qsort(i+1,right);
	}
}*/

void Qsort(int left,int right){
	string pivot,temp;
	int i,j;
	if(left<right){
		i=left;
		j=right+1;
		pivot=lines[left];
	
	do{
		do i++;while((lines[i].compare(pivot))>0);
		do j--;while((lines[j].compare(pivot))<0);
		if(i<j){
			swap(i,j);
		}
	}while(i<j);
	swap(left,j);
	
	Qsort(left,j-1);
	Qsort(j+1,right);
}

}



	
int main(void){

	string line;
	while(getline(cin,line)){
		lines.push_back(line);
	}

	Qsort(0,lines.size()-1);
	for(int i=lines.size()-1;i>=0;i--){
		cout<<lines[i]<<endl;
	}
		
	
}

