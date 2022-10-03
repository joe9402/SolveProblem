class Solution {
public:
    //https://leetcode.com/problems/couples-holding-hands/discuss/113362/JavaC%2B%2B-O(N)-solution-using-cyclic-swapping
    int minSwapsCouples(vector<int>& row) {
        int res = 0, N = row.size();
        
        vector<int> ptn(N, 0);
        vector<int> pos(N, 0);
        
        for(int i = 0 ; i < N; i++) {
            ptn[i] = (i % 2 == 0 ? i + 1 : i - 1);
            pos[row[i]] = i;
        }
        //loop 관련 다른 부분은 위 링크 참조
        //j = row[i] 를 j = ptn[pos[ptn[row[i]]]] 로 대체
        //j = ptn[pos[ptn[row[i]]]] 를 i -> j 라 할 때
        //1. 동일하게 i0 에서 시작하면 i0로 끝나는 루프
        //1-1 결국 반복문임 증명 : 숫자 개수상 N개의 숫자 N개의 방향성으로 반복문이 아닐수가 없다.
        //1-2 i0로 돌아온다. 아니라고 가정했을때 i -> p , j -> p 이면 p자리의 파트너 자리 숫자가 i,j와 모두 파트너이기 때문에 불가 함으로 중간 루프 없음
        //2. 서로 파트너인 자리를 그룹으로 묶을 때 하나의 루프에 그룹인 2자리가 모두 있을 수 없다.
        //2-1 A그룹의 자리를 a1, a2 라 할때 a1 -> a2 라고 하면 a1의 파트너가 a1 으로 스스로가 파트너 일수는 없다.
        //2-2 A그룹 a1,a2 / B 그룹 b1, b2 라고 할때 a1 -> b1 -> a2 이면 a1이 b1, b2와 동시에 파트너이게 됨으로 불가능하다.
        //따라서 시작 그룹에서 1개의 숫자가 결정되면 루프는 결과적으로 그룹간 연결이 되며 해당 루프가 해결되면 다른 숫자 군집 루프는 페어로 동작하기 때문에 자동으로 해소된다.
        //예를 들어 A그룹 a1에서 시작한 루프와 a2에서 시작한 루프가 있을때 a1에서 시작한 루프가 해소되면 a2에서 시작한 루프는 자동으로 해소된다.
        //2k개의 숫자에 대하여 그룹은 k개가 되고 k개의 원소 루프는 k-1번 스왑으로 해소된다.(j=row[i] 와 동일)
    
        
        for(int i = 0; i < N; i++){
            for(int j = ptn[pos[ptn[row[i]]]]; i != j; j = ptn[pos[ptn[row[i]]]]) {
                swap(row[i], row[j]);
                swap(pos[row[i]], pos[row[j]]);
                res++;
            }
        }
        
        return res;
    }    
};