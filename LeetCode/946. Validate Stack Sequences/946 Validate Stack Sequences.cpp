class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int stack[1000];
        int top = 0;
        int poptop = 0;
        stack[0] = pushed[0];
        int pushtop = 1;
        for(;popped.size()>poptop;poptop++){
            if(top < 0) {
                if(pushtop >= pushed.size()) return false;
                stack[0] = pushed[pushtop++];
                top = 0;
            }
            while(stack[top] != popped[poptop]) {
                if(pushed.size() <= pushtop) {
                    return false;
                }
                top++;
                stack[top] = pushed[pushtop++];
            }
            if(stack[top] == popped[poptop]) {
                top--;
            }
        }
        if(top < 0) return true;
        else return false;
    }
};