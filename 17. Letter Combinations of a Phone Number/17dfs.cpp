class Solution {
public:
    vector<string> result;
    vector<vector<string>> phone = {
	    {"a","b","c"},
	    {"d","e","f"},
    	{"g","h","i"},
    	{"j","k","l"},
    	{"m","n","o"},
	    {"p","q","r","s"},
	    {"t","u","v"},
	    {"w","x","y","z"}
    };
    void dfs(string digits, int lev, string s){
        if(digits.size() == lev){
            result.push_back(s);
        } else {
            for(int i = 0; i<phone[digits[lev]-'2'].size(); i++){
                dfs(digits,lev+1,s+phone[digits[lev]-'2'][i]);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() != 0) dfs(digits,0,"");
        return result;
    }
};