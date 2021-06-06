class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool check[10001] = {false};
        check[0] = true;
        for(int i = 0 ; i<nums.size(); i++){
            if(check[nums.size() - 1]) return true;
            if(check[i]){
                for(int j = i+1; j<=i+nums[i];j++){
                    if(j >= nums.size()-1) return true;
                    check[j] = true;
                }
            }
            
        }
        return false;
    }
    
};