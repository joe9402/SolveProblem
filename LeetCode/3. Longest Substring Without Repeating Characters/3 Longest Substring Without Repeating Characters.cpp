class Solution {
    //discuss 영상 참고
    //겹치는 부분이 나오면 이전 동일 char 부분을
    //시작점으로 삼는 슬라이딩 윈도우 방식
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> Map;
        int start = -1; //계산상 맨 앞 문자를 포함하기 위해 -1
        int res = 0;
        
        for(int i = 0; i < s.size();i++){
            if(Map.count(s[i]) != 0) {
                start = max(start, Map[s[i]]);
            }
            Map[s[i]] = i;
            res = max(res, i-start);
        }
        return res;
    }
};