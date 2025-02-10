class Solution {
public:
    string clearDigits(string s) {
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                res.push_back(s[i]);
            }
            else{
                res.pop_back();
            }
        }

        return res;
    }
};