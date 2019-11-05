
class MaxHeap{
	private:
	int *heap;
	int heapSize;
	int capacity;
	
	public:
	
	void changeSize1D(int*a,int oldSize,int newSize);
	
	MaxHeap();
	
	void push(int i);
	
	void pop();
	
	int top();
	
	void pop(int);
	
	int top(int);
	
	void print();
	
	int get_heapSize();
};
	
	
	
	
	
