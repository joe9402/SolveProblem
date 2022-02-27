class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int count[10001] = {0};
        
        int maxCount = 0;
        int maxPoint = 0;
        int maxint = 0;
        for(int i = 0; i<barcodes.size(); i++){
            count[barcodes[i]]++;
            if(maxCount < count[barcodes[i]]) {
                maxPoint = barcodes[i];
                maxCount = count[barcodes[i]];
            }
            if(maxint <  barcodes[i]) maxint = barcodes[i];
        }
        
        int point = 0;
        while(count[maxPoint]) {
            barcodes[point] = maxPoint;
            count[maxPoint]--;
            point +=2;
            if(point >= barcodes.size()) point = 1;
        }
        for(int i = 1 ; i <= maxint; i++){
            if(count[i] > 0) {
                while(count[i]) {
                    barcodes[point] = i;
                    count[i]--;
                    point += 2;
                    if(point >= barcodes.size()) point = 1;
                }
            }
        }
        return barcodes;
    }
};