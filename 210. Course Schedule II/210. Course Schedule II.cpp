class Solution {
public:
    vector<pair<int,int>> ss;
    vector<int> map[2001];
    vector<int> res;
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int tab[2001] = {0};
        for(auto a : prerequisites){
            map[a[1]].push_back(a[0]);
            tab[a[0]]++;
        }
        queue<int> qq;
        for(int i =0 ; i<numCourses;i++){
            if(tab[i] == 0)qq.push(i);
        }
        
        while(!qq.empty()){
            int now = qq.front();
            res.push_back(now);
            qq.pop();
            for(int i =0;i<map[now].size();i++){
                tab[map[now][i]]--;
                if(tab[map[now][i]] == 0) qq.push(map[now][i]);
            }
        }
        vector<int> aa;
        if(res.size() < numCourses) return aa;
        return res;
    } 
};