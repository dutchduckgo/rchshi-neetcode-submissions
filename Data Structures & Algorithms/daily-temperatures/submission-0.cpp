class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        // brute force: time: n^2, space: 1
        // 
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
    }
};
