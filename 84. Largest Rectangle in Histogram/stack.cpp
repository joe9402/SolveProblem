class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int stack[100001];
        stack[0] = 0;
        int max = heights[0];
        int top = 0;
        for(int i=1;i<heights.size();i++){
            while(top>=0 && heights[stack[top]] >= heights[i]){
                if(top == 0){
                    if(max < heights[stack[0]]*i){
                      max = heights[stack[0]]*i;
                  }
                 }
                 else{
                   if(max<heights[stack[top]]*(i-stack[top-1]-1)){
                       max = heights[stack[top]]*(i-stack[top-1]-1);
                   }
                 }
                top--;
            }
            stack[++top] = i;
        }
        for(int i = top; i>=0;i--){
            if(top == 0){
                if(max < heights[stack[0]]*(heights.size())){
                    max = heights[stack[0]]*heights.size();
                }
            }
            else{
                if(max<heights[stack[top]]*(heights.size()-stack[top-1]-1)){
                    max = heights[stack[top]]*(heights.size()-stack[top-1]-1);
                }
                top--;
            }
        }
        return max;
    }
};