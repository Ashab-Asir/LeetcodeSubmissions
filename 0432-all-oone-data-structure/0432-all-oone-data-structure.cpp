class AllOne {
public:
    unordered_map<string ,int>map;
    set<pair<int,string>> s;
    
    AllOne() {}
    
    
    void inc(string key) {
        int count= map[key];
        s.erase({count, key});
        
        map[key]++;
        s.insert({map[key], key});
    }
    
    
    void dec(string key) {
        int count= map[key];
        s.erase({count, key});
        
        map[key]--;
        
        if(map[key]==0) map.erase(key);
        else s.insert({map[key], key});
    }
    
    
    string getMaxKey() {
        return s.size()==0 ? "" :  s.rbegin()->second;
    }
    
    
    string getMinKey() {
        return s.size()==0 ? "" : s.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */