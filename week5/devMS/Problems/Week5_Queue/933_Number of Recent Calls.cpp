//933. Number of Recent Calls
//https://leetcode.com/problems/number-of-recent-calls/
//Runtime: 136 ms, faster than 64.64% of C++ online submissions for Number of Recent Calls.
//Memory Usage : 57.3 MB, less than 71.45 % of C++ online submissions for Number of Recent Calls.
// 
// 
//Time초과문제:처음에는 정석대로 range범위에 들어오는지 안들어오는지 모든 queue를 다 돌면서 일일히 셌는데 그러니까 너무 오래걸렸음.
//해결방법: 어차피 오름차순이니까 큐 내부 원소중에 lowBound보다 작은 부분까지만 pop을 하면 나머지는 다 low bound보다 큰부분이라서 
//거기까지만 pop을 하고 큐의 사이즈를 반환하는 함수를 썼다.

#include<queue>

class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {

    }

    int ping(int t) {
        q.push(t);

        //Get Range
        int lowBound = t - 3000;

        while (q.front() < lowBound)
        {
            q.pop();
        }
        return q.size();

    }

};