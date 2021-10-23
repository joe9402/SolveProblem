class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int tab[10001];
        int m;
        int mp;
        int min;
        int minp;
        if(nums1.size() == 1) return nums1;
        for(int i =0; i<nums2.size();i++){
            m = 1000000001;
            mp = -1;
            min = 1000000001;
            minp = -1;
            for(int j =0 ; j<nums1.size();j++){
                if(min > nums1[j] && nums1[j] >= 0){
                    min = nums1[j];
                    minp = j;
                }
                if(nums2[i]>=nums1[j])continue;
                if(nums1[j]-nums2[i] < m){
                    m = nums1[j]-nums2[i];
                    mp = j;
                }
            }
            if(mp != -1){
                tab[i] = nums1[mp];
                nums1[mp] = -1;
            }
            else {
                tab[i] = nums1[minp];
                nums1[minp] = -1;
            }
        
        }
        for(int i =0; i<nums1.size();i++){
            nums1[i] = tab[i];
        }
        return nums1;
    }
};