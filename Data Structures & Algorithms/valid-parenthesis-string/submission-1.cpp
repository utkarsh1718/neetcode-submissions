class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> s1; // for '('
        stack<int> s2; // for '*'

        // First pass
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                s1.push(i);
            }
            else if(s[i] == '*'){
                s2.push(i);
            }
            else{ // ')'
                if(s1.empty() && s2.empty()){
                    return false;
                }

                if(!s1.empty()){
                    s1.pop();
                }
                else{
                    s2.pop();
                }
            }
        }

        // Second pass
        while(!s1.empty() && !s2.empty()){
            if(s1.top() < s2.top()){
                s1.pop();
                s2.pop();
            }
            else{
                return false;
            }
        }

        if(s1.empty()) return true;
        return false;
    }
};