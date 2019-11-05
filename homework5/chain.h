class vertexdur_link;

class chain{
	friend class vertexdur_link;
	public:
		int in_num;
		vertexdur_link * first;
	
	
		chain();
		void add(int ,int);
		void set_in_num(int);

		int get_in_num();
		int get_dur(int);
		int get_node_num();
		
};
