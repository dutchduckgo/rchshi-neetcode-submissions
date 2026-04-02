class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq; // freq, char
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string str = "";
        while (!pq.empty()) {
            pair<int, char> top = pq.top();
            int freq = top.first;
            char ch = top.second;
            pq.pop();

            if (str.size() > 1 && 
                str[str.size() - 1] == ch && 
                str[str.size() - 2] == ch) {
                
                if (pq.empty()) break;
                auto [freq2, ch2] = pq.top();
                pq.pop();
                str += ch2;
                freq2 --;
                if (freq2 > 0) pq.push({freq2, ch2});
                pq.push({freq, ch});
            } else {
                str += ch;
                freq --;
                if (freq > 0) pq.push({freq, ch});
            }
        }
        return str;
    }
};