class NumberContainers {
public:
    unordered_map<int,priority_queue<int,vector<int>,greater<>>> mp1;
    unordered_map<int,int> mp2;
    int number;
    int index;
    NumberContainers() {
        int res1 = find(number);
        change(index,number);
    }
    
    void change(int index, int number) {
        mp1[number].push(index);
        mp2[index] = number;
    }
    
    int find(int number) {
        if(mp1.find(number) != mp1.end()){
            while(!mp1[number].empty()){
                if(mp2[mp1[number].top()] == number){
                    return mp1[number].top();
                }
                mp1[number].pop();
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */