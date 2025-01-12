class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2) return false;
        
        int balance = 0;
        int available = 0;

        for(int i=0;i<s.size();i++){
            if(locked[i] == '1'){
                if(s[i] == '('){
                    balance += 1;
                }
                else{
                    balance -= 1;
                }
            }
            else{
                available++;
            }

            if(balance + available < 0) return false;
        }

        balance = 0, available = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(locked[i] == '1'){
                if(s[i] == ')'){
                    balance += 1;
                }
                else{
                    balance -= 1;
                }
            }
            else{
                available++;
            }

            if(balance + available < 0) return false;
        }


        return true;
    }
};