#include <iostream>
#include "MaxHeap.h"

using namespace std;



MaxHeap::MaxHeap(){
	capacity=10;
	heap=new int[capacity+1];
	heapSize=0;
}

void MaxHeap::changeSize1D(int*a,int oldSize,int newSize){
	int *temp=new int[newSize];
	int num=min(oldSize,newSize);
	copy(a,a+num,temp);
	delete []a;
	a=temp;
}

void MaxHeap::push(int i){
	if(heapSize==capacity){
		changeSize1D(heap,capacity,2*capacity);
		capacity*=2;
	}
	int currentNode=++heapSize;
	while(currentNode!=1&&heap[currentNode/2]<i){
		heap[currentNode]=heap[currentNode/2];
		currentNode/=2;
	}
	heap[currentNode]=i;
		
}

void MaxHeap::pop(){
	int lastE=heap[heapSize--];
	int currentNode=1;
	int child=2;
	while(child<=heapSize){
		if(child<heapSize&&heap[child]<heap[child+1]){
			child++;
		}
		if(lastE>=heap[child]){
			break;
		}
		heap[currentNode]=heap[child];
		currentNode=child;
		child*=2;
		
	}
	heap[currentNode]=lastE;
}

int MaxHeap::top(){
	return heap[1];
}

void MaxHeap::print(){
	for(int i=1;i<=heapSize;i++){
		if(i==heapSize){
			cout<<heap[i]<<endl;
		}
		else{
			cout<<heap[i]<<" ";
		}
	}
}

int MaxHeap::get_heapSize(){
	return heapSize;
}

int MaxHeap::top(int i){
	int temp[heapSize];
	int t;
	for(int k=0;k<heapSize;k++){
		temp[k]=heap[k+1];
	}
	for(int n=0;n<heapSize-1;n++){
		for(int m=0;m<heapSize-1;m++){
			if(temp[m]<temp[m+1]){
				t=temp[m];
				temp[m]=temp[m+1];
				temp[m+1]=t;
			}
		}
	}
	return temp[i-1];

	
	
}

void MaxHeap::pop(int i){
	int temp[capacity];
	for(int k=0;k<capacity;k++){
		temp[k]=heap[k];
	}
	for(int k=0;k<i;k++){
		pop();
	}
	for(int k=1;k<i;k++){
		push(temp[k]);
	}
	}
	





