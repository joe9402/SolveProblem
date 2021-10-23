class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p = 0;
        while(true){
            int a = nums[p];
            if(a == 0) break;
            nums[p] = 0;
            p = a;
        }
        return p;
    }
};