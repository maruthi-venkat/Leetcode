class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        string word;
        int i = 1;
        vector<pair<string,int>> v;
        while(iss >> word){
            v.push_back({word,i});
            i++;
        }
        
        for(int _ = 0;_<v.size();_++){
            string mainword = v[_].first;
            int i=0;
            int j=0;
            while(i<mainword.size() && j<searchWord.size() && mainword[i] == searchWord[j]){
                i++;
                j++;
            }
            if(j == searchWord.size()){
                return v[_].second;
            }
        }

        return -1;
    }
};