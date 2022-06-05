class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() > 12) return res;
        int n = s.length();
        for(int i1 = 1; i1 <= 3; i1++) {
            string j1 = "";
            for(int k = 0; k < i1;k++){
                if(k >= n) break;
                j1+=s[k];
            }
            if(i1 >= n) continue;
            for(int i2 = 1; i2 <= 3; i2++) {
                string j2 = "";
                for(int k = 0; k < i2;k++){
                    if(i1+k >= n) break;
                    j2+=s[i1+k];   
                }
                if(i1+i2  >= n) continue;
                for(int i3 = 1; i3 <= 3; i3++) {
                    string j3 = "";
                    for(int k = 0; k < i3;k++){
                        if(i1+i2+k >= n) break;
                       j3+=s[i1+i2+k];
                    }
                    if(i1+i2+i3 >= n) continue;
                    for(int i4 = 1; i4 <= 3; i4++) {
                        string j4 = "";
                        for(int k = 0; k < i4;k++){
                            if(i1+i2+i3+k >= n) break;
                            j4+=s[i1+i2+i3+k];
                        }
                        if(i1+i2+i3+i4  > n) continue;
                        if(i1+i2+i3+i4  == n && checkOver(j1) && checkOver(j2) && checkOver(j3) && checkOver(j4)) {
                            res.push_back(j1+"."+j2+"."+j3+"."+j4);
                        }
                        //cout << j1 <<"."<<j2<<"."<<j3<<"."<<j4 << "   " << checkOver(j1)<< "   " << checkOver(j2)<< "   " << checkOver(j3)<< "   " << checkOver(j4)<<endl;
                    }
                }
            }
        }
        return res;
    }
    
    bool checkOver(string a){
        if(a.length() != 1 && a[0] == '0') return false;
        if(a.length() > 3) return false;
        if(a.length() <= 2) return true;
        int sum = 0;
        for(int i = 0; i< 3; i++){
            sum*=10;
            sum+=a[i]-'0';
        }
        if(sum > 255) return false;
        else return true;
    }
};