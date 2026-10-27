class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(auto nbr : rooms[curr]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }

        bool ans = true;
        for(int i = 0; i < visited.size(); i++) {
            if(visited[i] == false) ans = false;
        }

        return ans;
    }
};