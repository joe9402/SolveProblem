class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int burst[100001];
        vector<pair<int,int>> p_start;
        vector<pair<int,int>> p_end;
        //int p_start[100001][2];
        //int p_end[100001][2];
        for(int i = 0;i<points.size();i++){
            burst[i] = 0;
            p_start.push_back(pair(i,points[i][0]));
            p_end.push_back(pair(i,points[i][1]));
            //p_start[i][0] = i;p_start[i][1] = points[i][0];
            //p_end[i][0] = i;p_end[i][1] = points[i][1];
        }
        sort(p_start.begin(),p_start.end(),[](const pair<int,int> a, const pair<int,int> b){
        return a.second<b.second;
      });
        sort(p_end.begin(),p_end.end(),[](const pair<int,int> a, const pair<int,int> b){
        return a.second<b.second;
      });
        int count = 1;
        int myend = 0;
        for(int i = 0 ; i<points.size();i++){
            if(p_start[i].second <= p_end[myend].second){
                burst[p_start[i].first] = 1;
            }
            else {
                count++;
                while(true){
                    if(burst[p_end[myend].first] != 0){
                        myend++;
                    } else break;
                }                
                burst[p_start[i].first] = 1;
            }
            
        }
        return count;
    }
    
};