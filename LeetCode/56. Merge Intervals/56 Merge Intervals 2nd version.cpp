class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int point = 0;
        sort(intervals.begin(),intervals.end());
        while(1){
            if(point == intervals.size()){
                break;
            }
            vector<int> k;
            int start = intervals[point][0], end = intervals[point][1];
            k.push_back(start);
            while(1){
                if(point == intervals.size()-1){
                    if(end < intervals[point][1]) end = intervals[point][1];
                    k.push_back(end);
                    point++;
                    break;
                }
                if(end >= intervals[point+1][0]){
                    point++;
                    if(end < intervals[point][1]) end = intervals[point][1];
                } else {
                    if(end < intervals[point][1]) end = intervals[point][1];
                    k.push_back(end);
                    point++;
                    break;
                }
            }
            res.push_back(k);
        }
        return res;
    }
};