#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int n = s.size();
        std::stack<int> st;
        int i = 0;
        
        while (i < n) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                if (st.empty() || s[st.top()] != '(')
                    st.push(i);
                else if (s[st.top()] == '(')
                    st.pop();
            }
            i++;
        }
        
        int substr = 0;
        int end = n;

        while (!st.empty()) {
            int l = st.top();
            st.pop();
            substr = std::max(substr, end - l - 1);
            end = l;
        }

        substr = std::max(substr, end);
        return substr;
    }
};

int main() {
    Solution sol;
    std::string s = "(()())";
    std::cout << sol.longestValidParentheses(s) << std::endl;
    return 0;
}
