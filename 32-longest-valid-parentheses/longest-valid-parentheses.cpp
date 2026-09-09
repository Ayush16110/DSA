class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        st.push(-1); //defining the left boundary

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if(st.empty()) {
                    st.push(i); // new valid boundary
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};