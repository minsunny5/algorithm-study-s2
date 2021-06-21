//LeetCode 1021. Remove Outermost Parentheses
//Runtime: 4 ms, faster than 79.95% of C++ online submissions for Remove Outermost Parentheses.
//Memory Usage : 6.8 MB, less than 22.18 % of C++ online submissions for Remove Outermost Parentheses.
//https://leetcode.com/problems/remove-outermost-parentheses/submissions/

#include <stack>

class Solution {
    stack<char> inputStack;
    string result = "";
public:
    string removeOuterParentheses(string s) {

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                if (inputStack.size() >= 1)//When s[i] is inner parentheses
                {
                    inputStack.push(s[i]);
                    result.push_back(s[i]);
                }
                else//When s[i] is outer parentheses
                {
                    inputStack.push(s[i]);
                }

            }
            if (s[i] == ')')
            {
                if (inputStack.size() > 1)//When s[i] is inner parentheses
                {
                    inputStack.pop();
                    result.push_back(s[i]);
                }
                else//When s[i] is outer parentheses
                {
                    inputStack.pop();
                }
            }


        }

        return result;

    }

};