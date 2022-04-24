class Solution {
public:
    
    int* calc(int *tab, int count){
        for(int i = count; i > 0; i--){
            if(tab[i]>tab[i-1]) {
                tab[i]--;
                for(int j = i-1;j>=0;j--){
                    tab[j] = 9;
                }
                return calc(tab,count);
            }
        }
        return tab;
    }
    
    int monotoneIncreasingDigits(int n) {
        if (n<10) return n;
        //check monotone
        int N = n;
        int count =0;
        int tab[11] = {0};
        while(N > 0){
            tab[count++] = N % 10;
            N /= 10;
        }
        calc(tab,count);
        int res =0;
        for(int i = count; i>0;i--){
            res = res*10 + tab[i-1];
        }
        return res;
    }
}; 