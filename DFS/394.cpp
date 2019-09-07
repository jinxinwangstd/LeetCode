#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == ']') {
                string encoded, num;
                while (st.top() != '[') {
                    encoded.insert(0, 1, st.top());
                    st.pop();
                }
                st.pop();
                while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
                    num.insert(0, 1, st.top());
                    st.pop();
                }
                int k = 0;
                for (int j = 0; j < num.size(); j++) {
                    k *= 10;
                    k += (num[j] - '0');
                }
                for (int j = 0; j < k; j++)
                    for (char c : encoded)
                        st.push(c);
            }
            else
                st.push(s[i]);
        }
        int m = st.size();
        string res(m, ' ');
        for (int i = m - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};
