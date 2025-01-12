class Solution {
public:
    bool checkvalid(string s) {
        stack<char> stk;
        for(char c : s) {
            if(c == '(') {
                stk.push(c);
            } else if(c == ')') {
                if(stk.empty()) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
    
    bool canBeValid(string s, string locked) {
        if(s.size() % 2) return false;
        
        // Count locked parentheses and available positions
        int balance = 0;
        int available = 0;
        
        // Left to right pass - check for excess closing parentheses
        for(int i = 0; i < s.size(); i++) {
            if(locked[i] == '1') {
                balance += (s[i] == '(' ? 1 : -1);
            } else {
                available++;
            }
            
            if(balance + available < 0) return false;
        }
        
        balance = 0;
        available = 0;
        
        // Right to left pass - check for excess opening parentheses
        for(int i = s.size() - 1; i >= 0; i--) {
            if(locked[i] == '1') {
                balance += (s[i] == ')' ? 1 : -1);
            } else {
                available++;
            }
            
            if(balance + available < 0) return false;
        }
        
        return true;
    }
};