class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int arr1[10003] = {0};
        int arr2[10003] = {0};
        int sum = 0;
        int max =0;
        for(int i = 0;i<intervals.size();i++){
            arr1[intervals[i][0]+1] +=i+1;
            arr2[intervals[i][1]+1] +=i+1;
            if(max < intervals[i][1]) max=intervals[i][1];
        }
        int start = -1;
        for(int i = 1; i<10003;i++){
            arr1[i] += sum;
            if(start == -1){              
                if(arr1[i] != 0) {
                    start = i-1;
                }
            }
            sum = arr1[i] - arr2[i];
            if(start != -1 && sum == 0) {
                vector<int> a;
                a.push_back(start);
                a.push_back(i-1);
                res.push_back(a);
                start = -1;
            }
        }
        return res;
    }
};