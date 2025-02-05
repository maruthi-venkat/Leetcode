class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        vector<int> v;
        for(int i=0;i<s1.size();i++){
            if(s1[i] != s2[i]){
                count++;
                v.push_back(i);
            }
        }
        if(count == 0) return true;
        if(count == 2){
            swap(s2[v[1]],s2[v[0]]);
            if(s2 == s1) return true;
        }

        return false;
    }
};