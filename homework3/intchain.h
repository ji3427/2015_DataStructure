class intnode;

class intchain{
	friend class intnode;
	private:
	
	intnode *first;
	intnode * temp;
	
	public:
	intchain();
	
	void add(intnode *x,int num);
	
	void add(int num);
	
	void connect(intnode *x);
	
	intnode* getfirst();
	
	void setfirst(intnode *temp);
	
	void remove(int num);
	
	void print();
	
	void reverse();
	
	intnode* serch(int num);
	
	


};
