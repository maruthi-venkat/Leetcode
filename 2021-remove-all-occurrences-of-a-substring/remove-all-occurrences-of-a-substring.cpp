class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        int start = 0;
        for(int i=0;i<s.size();i++){
            string sub = s.substr(i,n);
            if(sub == part){
                s = s.substr(0,i) + s.substr(i+n,s.size());
                i=-1;
            }
        }

        return s;
    }
};