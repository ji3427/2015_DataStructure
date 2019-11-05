
class Stack
{
	
	private:
	int capacity;
	int top;
	char*stack;
	
	
	public:

	Stack(int stackCapcity);
	
	bool IsEmpty();
	
	char Top();
	
	void Push(char item);
	
	void Pop();
	
};

	

