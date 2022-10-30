class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int res = 0;
        int piv = nums.size();
        sort(nums.begin(), nums.end());
        int tab[1001] = {0};
        for(int i = 0; i < nums.size(); i++){
            tab[nums[i]]++;
        }
        for(int i = 1 ; i < 1001; i++){
            tab[i] += tab[i-1];
        }
        for(int i = 0 ; i < nums.size()-2;i++) {
            if(nums[i] == 0) continue;
            for(int j = nums.size()-1; j > i; j--){
                int sum = nums[i] + nums[j];
                if(sum > 1000) sum = 1001;
                if(sum < 1) sum = 1;
                res += tab[sum-1] - (j+1);
            }
        }
        return res;
    }
};