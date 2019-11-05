
class intnode{
	friend class intchain;
	private:
	int num;
	intnode *next;
	public:
	intnode(int num,intnode*next);
};
	
