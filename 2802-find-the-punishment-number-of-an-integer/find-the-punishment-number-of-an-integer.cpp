class Solution {
public:

    bool solve(string s,int m){
        if( s == "" && m == 0) return true;
        if(m < 0) return false;

        bool ans = false;

        for(int i=0;i<s.size();i++){
            string left = s.substr(0, i+1);
            string right = s.substr(i+1);
            int leftNum = stoi(left);

            bool isPossible = solve(right, m - leftNum);
            if(isPossible) { ans = true; break;}
        }

        return ans;
    }

    int punishmentNumber(int n) {
        int res = 0;
        for(int i=1;i<=n;i++){
            if(solve(to_string(i*i),i)){
                res += (i*i);
            }
        }

        return res;
    }
};