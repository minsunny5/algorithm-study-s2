//622. Design Circular Queue https://leetcode.com/problems/design-circular-queue/

#include <list>

class MyCircularQueue {
public:
    list<int> list;
    int MaxSize = 0;

    MyCircularQueue(int k) {
        MaxSize = k;
    }

    bool enQueue(int value) {
        list.push_back(value);
        if (MaxSize < list.size())
        {
            list.pop_back();
            return false;
        }
        return true;

    }

    bool deQueue() {
        if (list.empty())
            return false;

        list.pop_front();
        return true;

    }

    int Front() {
        if (list.empty())
        {
            return -1;
        }
        return list.front();

    }

    int Rear() {
        if (list.empty())
        {
            return -1;
        }
        return list.back();
    }

    bool isEmpty() {
        return list.empty();
    }

    bool isFull() {
        if (list.size() == MaxSize)
            return true;
        else if (list.size() < MaxSize)
            return false;
        else
            return false;
    }
};
