#include <iostream>
#include <cstdlib>
#include <string>
#include "vertexdur_link.h"
#include "chain.h"
#include <cstdio>


using namespace std;
int ln=0;

int main(void) {
	int vertex_num,temp;
	string line;
	vertex_num=0;
	int x=0;
	int k=0;
	
	
	while(getline(cin,line)){
		vertex_num++;
	}
	int num[vertex_num];
	int ee[vertex_num];
	int le[vertex_num];
	int torder[vertex_num];
	int edge_num=0;
	chain count[vertex_num];
	int z_num=0;
	for(int m=0;m<vertex_num;m++){
		ee[m]=0;
		num[m]=0;
		torder[m]=0;
	
	}
	cin.clear();
	cin.seekg(0,ios::beg);
	

	while(getline(cin,line)){
		int i;
		for(i=0;i<line.length();i++){
			if(line[i]==' '){
				temp=atoi(&line.c_str()[i+1]);
				num[temp]++;
			

			}
			if(line[i]==','){
				k=atoi(&line.c_str()[i+1]);
				count[ln].add(temp,k);
			}
		}
		count[ln].set_in_num(num[ln]);
		ln++;

	}

	for(int m=0;m<vertex_num;m++){
		edge_num+=count[m].in_num;
	}
	int e[edge_num];
	int l[edge_num];
	for(int m=0;m<vertex_num;m++){
		e[m]=0;
		l[m]=0;
	}
	

	int top=-1;
	for(int i=0;i<vertex_num;i++){
		if(count[i].in_num==0){
			count[i].in_num=top;
			top=i;
		}
	}
	for(int i=0;i<vertex_num;i++){
		if(top==-1){
		cout<<"AOE network error\n"<<endl;
		exit(-1);
	}
		int j=top;
		top=count[top].in_num;
		torder[i]=j;
		vertexdur_link * ji=count[j].first;
		while(ji){
			count[ji->vertex].in_num--;
			ee[ji->vertex]=max(ee[ji->vertex],ee[j]+count[j].get_dur(ji->vertex));
			if(count[ji->vertex].in_num==0){
				count[ji->vertex].in_num=top;
				top=ji->vertex;
			}
			ji=ji->next;
		}
		
	}
	for(int i=0;i<vertex_num;i++){
		if(ee[i]==0){
			z_num++;
		}
	}
	if(z_num!=1){
		cout<<"AOE network error\n"<<endl;
		exit(-1);
	}
		

		for(int k=0;k<vertex_num-1;k++){
			for(int i=count[k].get_node_num();i>0;i--){
				e[x]=ee[k];
				x++;
			}
		}
		
		le[vertex_num-1]=ee[vertex_num-1];
		int temp_v=vertex_num-2;
		int small;
		for(int i=0;i<vertex_num-1;i++){
			if(count[torder[temp_v]].get_node_num()==1){		
			le[torder[temp_v]]=le[count[torder[temp_v]].first->vertex]-count[torder[temp_v]].first->time;
			temp_v--;
		}	
			else{
				int temp2[count[torder[temp_v]].get_node_num()];
				vertexdur_link * t=count[torder[temp_v]].first;
				for(int i=0;i<count[torder[temp_v]].get_node_num();i++){
					temp2[i]=le[t->vertex]-t->time;
					t=t->next;
				}
				small=temp2[0];
				for(int i=1;i<count[torder[temp_v]].get_node_num();i++){
					if(small>temp2[i]){
						small=temp2[i];
					}
				}
				le[torder[temp_v]]=small;
				temp_v--;
			}
		
		}
		
		x=0;
		for(int k=0;k<vertex_num-1;k++){
			vertexdur_link * temp=count[k].first;
			for(int i=count[k].get_node_num();i>0;i--){
				l[x]=le[temp->vertex]-temp->time;
				x++;
				temp=temp->next;
			}
		}
		
		
	
		
	x=0;
	
	for(int i=0;i<edge_num;){
		vertexdur_link * temp=count[x].first;
		string rs;
		for(int j=count[x].get_node_num();j>0;j--){
			if(l[i]-e[i]==0){rs="Yes";}
			else{rs="No";}
			cout<<x<<','<<temp->vertex<<' '<<e[i]<<' '<<l[i]<<' '<<l[i]-e[i]<<' '<<rs<<endl;
			i++;
			temp=temp->next;
		}
		x++;
		
	}

	
	
}
	

