class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]]++;
            }
            else{
                mp[s[i]] = 1;
            }
        }
        int count = 0;
        
        for(auto it : mp){
            if(it.second % 2 == 1){
                count++;
            }
            cout<<it.first<<" "<<it.second<<endl;
        }

        if(count > k){
            return false;
        }

        return true;
    }
};