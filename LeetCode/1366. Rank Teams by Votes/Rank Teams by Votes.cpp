class Solution {
public:
    bool comp(vector<int> a, vector<int> b) {
        for(int i =0 ;i < 26; i++){
            if(a[i] > b[i]) return true;
            if(a[i] < b[i]) return false;
        }
        if(a[26] < b[26]) return true;
        else return false;
    }
    
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> count(26, vector<int>(27));
	    for (char& c : votes[0]) {
            count[c - 'A'][26] = c;
        }
        for (string& vote : votes) {
            for (int i = 0; i < vote.length(); ++i) {
                ++count[vote[i] - 'A'][i];
                //--count[vote[i] - 'A'][i];
            }
        }
        char aa;
        vector<int> cmp;
        for(int i =0 ; i< 26; i++){
            aa = count[i][26];
            for(int j = i+1 ;j < 26; j++){
                if(!comp(count[i],count[j])){
                    cmp = count[i];
                    count[i] = count[j];
                    count[j] = cmp;
                }
            }
        }
        //sort(count.begin(), count.end());
        string res;
        for (int i = 0; i < votes[0].length(); ++i)
            res += count[i][26];
        return res;
    }
};