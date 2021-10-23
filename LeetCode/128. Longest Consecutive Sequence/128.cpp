class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        
        int result = 0;
        
        unordered_map<int, bool> umap;
        
        for(int i =0;i<nums.size();i++){
            umap.insert(make_pair(nums[i],true));
        }
        
        for(int i =0 ;i<nums.size();i++){
            if(!umap.count(nums[i]-1)) {
                int cnum = nums[i];
                int ccount = 1;
                
                while(umap.count(cnum+1)){
                    cnum++;
                    ccount++;
                }
                
                result = max(ccount, result);
            }
        }
        return result;
    }
};