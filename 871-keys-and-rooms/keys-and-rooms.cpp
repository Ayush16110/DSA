class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto nbr : rooms[curr]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }

        for (bool seen : visited) {
            if (!seen)
                return false;
        }
        return true;
    }
};