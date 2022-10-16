class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> count;
        int MAX = 0;
        for(int i = 0 ; i < wall.size();i++){
            int sum = 0;
            for(int j = 0; j < wall[i].size()-1; j++) {
                sum += wall[i][j];
                count[sum]++;
                if (MAX < count[sum])
                    MAX = count[sum];
            }
        }
        return wall.size() - MAX;
    }
};