#include "sort.h"
#include "DataStruct.h"

template<typename T> Heap<T>::Heap()
{
	for(int i = 0; i<MAX_SIEZ ; ++i)
	{
		seq[i] = i;
	}
	
	memset(data,0,sizeof(T)*MAX_SIZE);

	heap_size = 0;
	length = 0;
}

template<typename T> Heap<T>::Heap(const T *sr,int size)
{
	for(int i = 0 ; i<MAX_SIZE ; ++i)
	{
		seq[i] = i;
	}
	
	heap_size = size;
	length = size;

	memcpy(data,sr,sizeof(T)*size);
}

template<typename T> Heap<T>::~Heap()
{
	heap_size = 0;
	length = 0;
	
	memset(data,0,sizeof(T)*MAX_SIZE);
	memset(seq,0,sizeof(int)*MAX_SIZE);
}

template<typename T> int Heap<T>::left(int i)
{
	return i<<1;
}

template<typename T> int Heap<T>::right(int i)
{
	return (i<<1)+1;
}

template<typename T> int Heap<T>::parent(int i)
{
	return i>>1;
}

template<typename T> void Heap<T>::exchange(int i ,int j)
{
	int temp = seq[i];
	seq[i] = seq[j];
	seq[j] = temp;
}

template<typename T> T& Heap<T>::minimum()
{
	return data[seq[1]];	
}

template<typename T> T& Heap<T>::extract_minimum()
{
	exchange(1,heap_size);
	heap_size -= 1;

	min_heap(1);
}

template<typename T> void Heap<T>::min_heap(int pos)
{
	int l = left(pos);
	int r = right(pos);

	int smallest = pos;

	if(l <= heap_size && data[l].key < data[smallest].key)
	{
		smallest = l;
	}

	if(r <= heap_size && data[r].key < data[smallest].key)
	{
		smallest = r;
	}

	if(smallest != pos)
	{
		exchange(pos,smallest);
		min_heap(smallest);
	}
	
}

template<typename T> void Heap<T>::min_heap_insert(int pos)
{
	int p = parent(pos);

	smallest = p;

	if(data[pos].key < data[smallest].key)
	{
		smallest = pos;
	}

	if(smallest != p)
	{
		exchange(smallest,p);
		min_heap_insert(p);
	}
}

template<typename T> void Heap<T>::build_min_heap()
{
	int length = heap_size/2;

	for(int i = length ; i>=1 ; --i)
	{
		min_heap(i);
	}
}

template<typename T> void Heap<T>::heapsort()
{
	int length = heap_size;

	for(int i =1 ; i<length ; ++i)
	{
		exchange(1,heap_size);
		heap_size -= 1;
		min_heap(1);
	}
}

template<typename T> void Heap<T>::insert(T elem)
{
	heap_size += 1;
	
	data[heap_size] = elem;

	min_heap_insert(heap_size);
}


template<typename T> void Heap<T>::decreaseKey(int pos,int value)
{
	data[pos].key = value;

	min_heap_insert(pos);
}

template<typename T> void Heap<T>::increaseKey(int pos ,int value)
{
	data[pos].key = value;
	
	min_heap(pos);
}



