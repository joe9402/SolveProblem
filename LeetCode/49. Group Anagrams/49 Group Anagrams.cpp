class Solution {
public:
    int tab[10001][31];
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(int i = 0 ; i < strs.size(); i++){
            for(int j = 0; j < strs[i].length();j++){
                tab[i][strs[i][j]-'a']++;
            }
        }
        vector<vector<string>> res;
        for(int i = 0 ; i < strs.size();i++){
            if(tab[i][30]==1) continue;
            vector<string> subGroup;
            subGroup.push_back(strs[i]);
            tab[i][30] = 1;
            for(int j = i; j<strs.size(); j++){
                if(tab[j][30] == 1) continue;
                for(int k = 0 ; k < 28; k++){
                    if(tab[i][k] != tab[j][k]){
                        break;
                    }
                    if(k == 27) {
                        subGroup.push_back(strs[j]);
                        tab[j][30] = 1;
                    }
                }
            }
            res.push_back(subGroup);
        }
        return res;
    }
};