class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        vector<int> hash1(26,0);
        for(auto ch : str1){
            hash1[ch-'a']++;
        }

        vector<int> hash2 (26,0);
        for(auto ch : str2){
            hash2[ch-'a']++;
        }

        for(int i=0;i<26;i++){
            if(hash1[i] == hash2[i]){
                hash1[i] = 0;
                hash2[i] = 0;
            }
            else if(hash1[i] < hash2[i]){
                hash1[i] = 0;
                hash2[i] = hash2[i] - hash1[i];

                    if(hash1[(26 + i-1) % 26] >= hash2[i]){
                        hash1[(26 + i-1) % 26] -= hash2[i];
                        hash2[i] = 0;
                    }
                    else{
                        hash2[i] -= hash1[(26 + i-1) % 26];
                        hash1[(26 + i-1) % 26] = 0;
                    }
                

                    
            }
            else{
                hash1[i] -= hash2[i];
                hash2[i] = 0;
            }
        }

        

        int i=0;
        int j=0;
        while(i<str1.size() && j<str2.size()){
            if(str1[i] == str2[j] || 'a' + ((str1[i] - 'a' + 1) % 26)== str2[j]){
                j++;
            }
            i++;
        }

        if(j < str2.size()){
            return false;
        }
        return true;
    }
};