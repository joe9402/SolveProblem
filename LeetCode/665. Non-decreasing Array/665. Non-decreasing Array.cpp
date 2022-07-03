class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag = 0; //변경 횟수 확인
        for(int i = 1; i < nums.size();i++){
            //감소하는 상황 발생시 진입
            if(nums[i-1] > nums[i]) {
                if(++flag > 1) return false;
                //감소 하는 상황에서  i-1 위치 혹은 i 위치의 값을 변경해서 non-decreasing하게 만들어야 한다.
                //1. i-1 위치를 바꿔야 하는 경우
                //- i == 1 일 때 0번을 낮추는 것이 1번을 높이는 것 보다 뒷 부분의 가능 범위가 크다
                //- i-2 부분이 i 번째 이하의 수 일 경우 i-1을 낮추는 것이 뒷 부분의 가능 범위가 크다
                if(i<2 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                //2. i 위치를 바꾸어야 하는 경우
                //1에 해당하지 않는 모든 경우 i-1을 바꾸면 non-decreasing 하지 않기 때문에 i 위치의 값을 변경한다.
                else nums[i] = nums[i-1];
            }
            
        }
        return true;
    }
    //아래의 디스커스 설명 참고
    //https://leetcode.com/problems/non-decreasing-array/discuss/2193070/C%2B%2B-oror-Simple-Code-oror-Full-Explanation
};