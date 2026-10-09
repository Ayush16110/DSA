class Solution {
public:
    int minInsertions(string s) {
        int insert = 0;
        int balance = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') balance++;
            if(s[i] == ')') {
                if(i + 1 < s.length() and s[i + 1] == ')') i++;
                else insert++;
                balance--;
            }    
            if(balance < 0 ) {
                balance++;
                insert++;
            }
        }

        if(balance > 0) {
            insert += balance * 2;
            balance = 0;
        }

        if(balance < 0) {
            insert += balance;
            balance = 0;
        }

        return insert;
    }
};