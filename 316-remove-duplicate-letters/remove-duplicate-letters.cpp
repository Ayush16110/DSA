class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastOcc(26, 0);
        string st;
        vector<bool> present(26, 0);

        for(int i = 0; i < s.length(); i++) {
            lastOcc[s[i] - 'a'] = i;
        }

        for(int i = 0; i < s.length(); i++) {
            if(present[s[i] - 'a'] == 1) continue;
            while(!st.empty() and st.back() > s[i] and i < lastOcc[st.back() - 'a']) {
                present[st.back() - 'a'] = 0;
                st.pop_back();
            }

            st.push_back(s[i]);
            present[st.back() - 'a'] = 1;
        }

        return st;
    }
};