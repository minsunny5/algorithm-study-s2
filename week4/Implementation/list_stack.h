#include "list.h"

template <typename T>
class ListQueue {
	LinkedList<T> list;

public:
	T& peek()
	{
		return list.back();
	}

	void pop()
	{
		list.pop_back();
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
