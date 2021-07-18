class Solution {
public:    
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int tab[100001];
        int n = nums1.size();
        priority_queue<pair<int , int>,vector<pair<int , int>>,cmp> pq;
        for(int i = 0;i<nums2.size();i++){
            pq.push(pair<int, int>(i, nums2[i]));
        }
        sort(nums1.begin(), nums1.end());
        int l =0; int r=nums1.size() -1;
        int a =0;
        while(!pq.empty()){
            pair<int , int > a = pq.top();pq.pop();
            if(nums1[r]<=a.second){
                tab[a.first] = nums1[l];
                l++;
            }
            else {
                tab[a.first] = nums1[r];
                r--;
            }
        }
        for(int i =0;i<nums1.size();i++){
            nums1[i] = tab[i];
        }
        return nums1;
    }

    struct cmp{
        bool operator()(pair<int , int> a, pair<int , int> b){
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        }
    };
};