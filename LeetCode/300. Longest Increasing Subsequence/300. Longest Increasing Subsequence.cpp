class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int count = 1;
        int arr[2501];
        arr[0] = nums[0];
        for(int i = 1; i<nums.size(); i++){
            int p = lower_bound(arr,arr+count,nums[i]) - arr;
            if(p >= count){
                arr[count] = nums[i];
                count++;
            } else {
                arr[p] = nums[i];
            }
        }
        return count;
    }
};