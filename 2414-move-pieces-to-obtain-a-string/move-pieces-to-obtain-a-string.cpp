class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = n-1, j = n-1;
        int cr1=0,cr2=0,cl1=0,cl2=0;
        for(int i=0;i<n;i++){
            if(start[i] == 'R'){
                cr1++;
            }
            else if(start[i] == 'L'){
                cl1++;
            }

            if(target[i] == 'R'){
                cr2++;
            }
            else if(target[i] == 'L'){
                cl2++;
            }
        }

        if(cr1 != cr2 || cl1 != cl2){
            return false;
        }
        while(j >= 0){
            if(target[j] == 'R'){
                i = min(i,j);
                bool found = false;
                while(i >= 0){
                    if(start[i] == 'R'){
                        i--;
                        found = 1;
                        break;
                    }
                    else if(start[i] == 'L'){
                        return false;
                    }
                    i--;
                }
                if(!found) return false;
            }
            j--;
        }
        for(int i=0;i<n;i++){
            if(start[i] == 'R'){
                start[i] = '_';
            }
            
            if(target[i] == 'R'){
                start[i] = 'R';
            }
        }
        i=0;
        j=0;
        while(j < n){
            if(target[j] == 'L'){
                i = max(i,j);
                bool found = 0;
                while(i < n){
                    if(start[i] == 'L'){
                        i++;
                        found = 1;
                        break;
                    }
                    else if(start[i] == 'R'){
                        return false;
                    }
                    i++;
                }
                if(!found) return false;
            }
            j++;
        }
        
        return true;
    }
};