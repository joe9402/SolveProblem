class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int tab[101][257];
        int N = n;
        for(int i =0; i < 257; i++){
            tab[0][i] = i;
            tab[1][i] = calc(i);
        }
        for(int i = 1; i < 101; i++){
            for(int j = 0; j< 257; j++){
                tab[i][j] = tab[1][tab[i-1][j]];
            }
        }
        int res = invertVetorToInt(cells);
        while(N > 100) {
            res = tab[100][res];
            N -= 100;
        }
        return invertIntToVector(tab[N][res]);
    }
    
    int calc(int k){
        vector<int> from = invertIntToVector(k);
        vector<int> res;
        res.push_back(0);
        
        for(int i = 1; i <7; i++){
            if(from[i-1] != from[i+1]) res.push_back(0);
            else res.push_back(1);
        }
        res.push_back(0);
        return invertVetorToInt(res);
    }
    
    int invertVetorToInt(vector<int> k){
        int res = 0;
        int x = 1;
        for(int i = 0; i < 8; i++){
            if(k[i] == 1) res += x;
            x *= 2;
        }
        return res;
    }
    
    vector<int> invertIntToVector(int k) {
        vector<int> res;
        for(int i = 0; i< 8; i++){
            res.push_back(k%2);
            k/=2;
        }
        return res;
    }
};