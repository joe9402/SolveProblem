class Solution {
public:    
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp (len, vector <bool> (len, false));
        vector<string> currentList;
        dfs(s, 0, currentList, dp);
        return res;
    }

    void dfs(string &s, int start, vector<string> &currentList, vector<vector<bool>> &dp) {
        if (start >= s.length()) res.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
};
