//LeetCode 20. https://leetcode.com/problems/valid-parentheses/

#include <stack>

class Solution {
    stack<char> inputStack;
    char top;

public:
    bool isValid(string s) {

        //왼쪽괄호를 만나면 스택에 푸시하고 오른쪽 괄호를 만나면 스택을 팝해서 그 괄호랑 stack의 top이랑 같은 pair인지 확인  
        for (int i = 0; i < s.length(); i++)
        {
            //When you meet left parentheses, push it to the stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') 
            {
                inputStack.push(s[i]);
            }
            //When you meet right parentheses, pop and check the top of the input stack is pair of it or not.
            if (s[i] == ')' || s[i] == ']' || s[i] == '}') 
            {

                if (!inputStack.empty())
                {
                    top = inputStack.top();
                    inputStack.pop();
                    if (!isPair(top, s[i]))
                    {
                        return false;
                    }
                }
                //If inputStack is empty and there are right parentheses, It cannot make pair of left parentheses. So false.
                //만약 inputStack이 비어있는 상태에서 오른쪽 괄호가 있다 ? 무조건 false임.짝(왼쪽괄호)이 없으니까
                else
                {
                    return false;
                }

            }
        }
        //After all, if there is something in the stack, It coudn't find pair. So return false.
        //그런 과정이 다 끝나고 나서 만약 스택에 뭐가 남아있다면 짝을 못찾은거니까 false를 반환한다.
        if (!inputStack.empty())
        {
            return false;
        }
        return true;

    }

    bool isPair(char leftP, char rightP)
    {
        if (leftP == '{')
        {
            if (rightP == '}')
                return true;
        }
        if (leftP == '(')
        {
            if (rightP == ')')
                return true;
        }
        if (leftP == '[')
        {
            if (rightP == ']')
                return true;
        }
        return false;
    }
};