class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>stack;
        for(char ch:s)
        {
            if(ch=='(')
            {
                stack.push(0);
            }
            else
            {
                int top=stack.top();
                stack.pop();
                int score=top==0 ? 1:2*top;
                if(!stack.empty())
                {
                    stack.top()+=score;
                }
                else
                {
                    stack.push(score);
                }
            }

        }
        return stack.top();
    }
};
