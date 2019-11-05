class vertexdur_link{
	friend class chain;
	public:
	int vertex;
	int time;
	vertexdur_link * next;
	
	
		vertexdur_link(int v,int t,vertexdur_link *next);
};
