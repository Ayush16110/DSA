class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> calendar = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        pair<int, int> alice = {0, 0};
        pair<int, int> bob = {0, 0};
        int count = 0;
        for(int i = 1; i < 13; i++) {
            for(int j = 1; j <= calendar[i]; j++) {
                count++;
                if(i == stoi(arriveAlice.substr(0, 2)) && j == stoi(arriveAlice.substr(3, 2)))
                    alice.first = count;
                if(i == stoi(leaveAlice.substr(0, 2)) && j == stoi(leaveAlice.substr(3, 2))) 
                    alice.second = count;
                if(i == stoi(arriveBob.substr(0, 2)) && j == stoi(arriveBob.substr(3, 2))) 
                    bob.first = count;
                if(i == stoi(leaveBob.substr(0, 2)) && j == stoi(leaveBob.substr(3, 2))) 
                    bob.second = count;
            }
        }

        if(alice.first <= bob.second && bob.first <= alice.second) {
            return min(alice.second, bob.second) - max(alice.first, bob.first) + 1;
        } 

        return 0;
    }
};