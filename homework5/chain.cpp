#include "chain.h"
#include "vertexdur_link.h"


using namespace std;

chain::chain(){
	in_num=0;
	first=0;
}
void chain::set_in_num(int in_num){
	this->in_num=in_num;
}
int chain::get_in_num(){
	return in_num;
}
void chain::add(int vertex,int time){
	if(first){
		vertexdur_link *temp=first;
		for(;temp->next!=0;temp=temp->next);
		temp->next=new vertexdur_link(vertex,time,0);
	}
	
	else
	first=new vertexdur_link(vertex,time,0);

}
int chain::get_dur(int i){
	vertexdur_link *temp=first;
	for(;temp->vertex!=i;temp=temp->next);
	return temp->time;
}
int chain::get_node_num(){
	int j=0;
	vertexdur_link *temp=first;
	for(;temp->next!=0;temp=temp->next){
		j++;
	}
	return j+1;
}

