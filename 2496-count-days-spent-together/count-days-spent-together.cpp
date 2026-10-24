class Solution {
    vector<int> calendar = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
private:
    int days(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        for(int i = 1; i <= month - 1; i++) {
            day += calendar[i];
        }
        return day;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceArrive = days(arriveAlice);
        int aliceLeave = days(leaveAlice);
        int bobArrive = days(arriveBob);
        int bobLeave = days(leaveBob);

        int start = max(aliceArrive, bobArrive);
        int end = min(aliceLeave, bobLeave);

        return max(end - start + 1, 0);
    }
};