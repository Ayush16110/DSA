class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string directory;
        stack<string> s;

        while(getline(ss, directory, '/')) {
            if(directory == "" || directory == ".") {
                continue;
            }
            if(directory == "..") {
                if(!s.empty()) {
                    s.pop();
                }
            } else {
                s.push(directory);
            }
        }

        string ans = "";
        while(!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};