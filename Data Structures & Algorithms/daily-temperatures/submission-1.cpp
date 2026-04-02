class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        /*
        stack<pair<int, int>> st;
        vector<int> res(temps.size(), 0);
        st.push({temps[0], 0});

        for (int i = 1; i < temps.size(); i ++) {
            while (!st.empty() && temps[i] > st.top().first) {
                pair<int, int> p = st.top();
                res[p.second] = i - p.second;
                st.pop();
            }
            st.push({temps[i], i});
        }
        return res;
        */

        stack<int> st;
        vector<int> res(temps.size(), 0);

        for (int i = 0; i < temps.size(); i ++) {
            while (!st.empty() && temps[i] > temps[st.top()]) {
                int idx = st.top();
                int t = temps[idx];
                res[idx] = i - idx;
                st.pop();
            }
            st.push(i);
        }
        return res;



    }
};
