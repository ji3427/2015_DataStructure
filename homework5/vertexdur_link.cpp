#include <iostream>
#include "vertexdur_link.h"

using namespace std;

vertexdur_link::vertexdur_link(int v,int t,vertexdur_link*next){
	vertex=v;
	time=t;
	next=next;
}

