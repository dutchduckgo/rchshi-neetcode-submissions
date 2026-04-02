class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (string& c : tokens) {
            if (c == "+") {
                int n2 = stack.top();
                stack.pop();
                int n1 = stack.top();
                stack.pop();
                stack.push(n1 + n2);
            } 
            else if (c == "-") {
                int n2 = stack.top();
                stack.pop();
                int n1 = stack.top();
                stack.pop();
                stack.push(n1 - n2);
            }
            else if (c == "*") {
                int n2 = stack.top();
                stack.pop();
                int n1 = stack.top();
                stack.pop();
                stack.push(n1 * n2);
            }
            else if (c == "/") {
                int n2 = stack.top();
                stack.pop();
                int n1 = stack.top();
                stack.pop();
                stack.push(n1 / n2);
            }
            else {
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }
};
