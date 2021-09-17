class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1,m;
        if(nums.size() == 1){
            if(nums[0] == target) return 0;
            else return -1;
        }
        while(l<r){
            m = (l+r)/2;
            if(nums[m]>nums[r]){
                l=m+1;
            }
            else {
                r=m;
            }
        }
        if(r == 0){
            int low = lower_bound(nums.begin(), nums.end(),target) - nums.begin();
            if(low >= nums.size())return -1;
            if(nums[low] == target) return low;
            else return -1;
        } else if(nums[nums.size() - 1] >= target) {
             int low = lower_bound(nums.begin() + l, nums.end(),target) - nums.begin();
            if(nums[low] == target) return low;
            else return -1;
        } else {
            int low = lower_bound(nums.begin(), nums.begin()+l-1,target) - nums.begin();
            if(nums[low] == target) return low;
            else return -1;
        }
    }
};