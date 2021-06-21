//155. Min Stack https://leetcode.com/problems/min-stack/

#include <vector>

class MinStack {
public:
    vector<int> list;
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        list.push_back(val);
    }

    void pop() {
        list.pop_back();
    }

    int top() {
        return list.back();
    }

    int getMin() {
        vector<int>::iterator iter = list.begin();
        int minVal = 2147483647;//max value of int type
        for (; iter != list.end(); iter++)
        {
            if (*iter < minVal)
            {
                minVal = *iter;
            }
        }
        return minVal;
    }
};
