class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i ++) {
            char c = s[i];
            if (c == '[') {
                st.push('[');
            } else if (c == '(') {
                st.push('(');
            }
            else if (c == '{') {
                st.push('{');
            } else if (c == ']') {
                if (!st.empty() && st.top() == '[') st.pop();
                else return false;
            } else if (c == ')') {
                if (!st.empty() && st.top() == '(') st.pop();
                else return false;
            }
            else if (c == '}') {
                if (!st.empty() && st.top() == '{') st.pop();
                else return false;
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};
