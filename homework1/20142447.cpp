#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Term{
	public:
	int alphabat;
	int coef=1;
	int exp;
};
class Section{
	
	public:
	Term* TermArray;
	

};


class polynomial{
	public:
	int capacity;
	Section * SectionArray;
	polynomial add(polynomial poly);
	
};




class readString{
	public:
	string polystring;
	int ap;
	int propmpt;
	int plus_point;
	
	int plus_num(){
	int p_num=0,num=0;
	while(polystring[num]!='\0'){
	if(polystring[num]=='+'){
   	p_num++;
   	num++;
   }
   else
   num++;
}
   return p_num;
}
		//플러스의 개수 파악(플러스 개수 +1=항의 수) 
	int alphabat_num(){
		
		int a_num=0,num=ap;
	
	while(polystring[num]!='+'){
	if(polystring[num]>='a'&&polystring[num]<='z')
	{
		a_num++;
		num++;
	}
	else{
	num++;
}
}
	ap=num+1;
	return a_num;
}
 //한 항의 알파벳의 개수 파악
	void ap_to_zero(){
		ap=0;
	}
	void propmpt_to_zero(){
		propmpt=0;
	}
	void plus_point_to_zero(){
		plus_point=0;
	}
		
		
};



int main(int argc, char** argv){
	
	//cout<<"hello";
	ifstream ifile;
	ifile.open(argv[1]);
	ofstream ofile;
	ofile.open(argv[2]);
	string polystring;
	int p_num;//다 항식의 플러스 개수
	int a_num;//한 항의 알파벳 개수
	
	readString rs;

	polynomial poly;


	while(getline(ifile,polystring)){
	rs.polystring=polystring;
	rs.ap_to_zero();
	rs.propmpt_to_zero();
	p_num=rs.plus_num();
	poly.SectionArray=new Section[p_num+1];
	for(int i=0;i<p_num+1;i++){
		a_num=rs.alphabat_num();
		poly.SectionArray[i].TermArray=new Term[a_num];
		if(i==0)
		{
			if(rs.polystring[i]>='a'&&rs.polystring[i]<='z')
			{
				poly.SectionArray[i].TermArray[0].coef=1;				
			}
			else
			{	
				poly.SectionArray[i].TermArray[0].coef=atoi(&polystring[0]);
				for(;'a'>rs.polystring[rs.propmpt]||'z'<rs.polystring[rs.propmpt];rs.propmpt++){
					if(rs.polystring[rs.propmpt]=='\0'){
			break;
		}
				}
			}
		}
		else
		{
			if(rs.polystring[rs.plus_point+1]==rs.polystring[rs.propmpt])
			{
				poly.SectionArray[i].TermArray[0].coef=1;
			}
			else
			{
				poly.SectionArray[i].TermArray[0].coef=atoi(&polystring[rs.plus_point+1]);
			}
		}
	for(int j=0;j<a_num;j++){
		poly.SectionArray[i].TermArray[j].alphabat=rs.polystring[rs.propmpt];
		if('a'<=rs.polystring[rs.propmpt+1]&&rs.polystring[rs.propmpt+1]<='z'&&'a'<=rs.polystring[rs.propmpt]&&rs.polystring[rs.propmpt]<='z'){
			poly.SectionArray[i].TermArray[j].exp=1;
			rs.propmpt++;
		}
		else
		{
			poly.SectionArray[i].TermArray[j].exp=atoi(&rs.polystring[rs.propmpt+2]);
			rs.propmpt++;
			for(;'a'>rs.polystring[rs.propmpt]||'z'<rs.polystring[rs.propmpt];rs.propmpt++){
				if(rs.polystring[rs.propmpt]=='\0'){
			break;
		}
		}
	
	
}
rs.plus_point++;
for(;rs.polystring[rs.plus_point]!='+';rs.plus_point++){
	if(rs.polystring[rs.plus_point]=='\0')
	{
		break;
		}
	}


}
}
		cout<<poly.SectionArray[0].TermArray[0].coef<<endl;
		cout<<poly.SectionArray[0].TermArray[0].exp<<endl;
		cout<<poly.SectionArray[0].TermArray[0].alphabat<<endl;
	

ifile.close();
ofile.close();

}
}
