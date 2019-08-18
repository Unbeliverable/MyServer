#ifndef SORT_H_
#define SORT_H_

const int MAX_SIZE = 256;

template<typename T>
	class Heap
	{
	public:
		Heap();//空堆的初始化
		~Heap();
		Heap(const T* sr,int size);//利用包含size个T变量的数组创建堆

		int left(int i);
		int right(int i);
		int parent(int i);
		void exchange(int i,int j);
		
		void min_heap(int pos);
		void min_heap_insert(int pos);

		T & minimum();
		T & extract_minimum();

		void decreaseKey(int pos,int value);
		void increaseKey(int pos,int value);
		void build_min_heap();
		void heapsort();
		void insert(T elem);
	private:
		int heap_size;
		int length;
		T data[MAX_SIZE];
		int seq[MAX_SIZE];
	};

#endif