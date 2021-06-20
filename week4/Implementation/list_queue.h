#include "list.h"

template <typename T>
class ListQueue {
	LinkedList<T> list;

public:
	T& front()
	{
		return list.front();
	}
	
	void pop()
	{
		list.pop_front();
	}

	bool empty()
	{
		return list.empty();
	}

	int size()
	{
		return list.size();
	}

	void push(T& val)
	{
		list.push_back(val);
	}
};