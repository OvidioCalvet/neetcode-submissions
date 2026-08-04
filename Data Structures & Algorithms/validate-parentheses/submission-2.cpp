class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        if(s.length() < 2) { return false; }

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ')') {
                if(!stack.empty() && stack.top() == '(')
                    stack.pop();
                else
                    return false;
            } else if(!stack.empty() && s[i] == '}') {
                if(stack.top() == '{')
                    stack.pop();
                else
                    return false;
            } else if(!stack.empty() && s[i] == ']') {
                if(stack.top() == '[')
                    stack.pop();
                else 
                    return false;
            } else {
                stack.push(s[i]);
            }
        }
        if(stack.empty()) { return true; }
        else { return false; }
    }
};
