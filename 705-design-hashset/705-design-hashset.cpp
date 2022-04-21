class MyHashSet {
    vector<bool> inSet;
public:
    MyHashSet() {
        inSet= vector<bool> (1e6 +2, 0);
    }
    
    void add(int key) {
        inSet[key]=true;
    }
    
    void remove(int key) {
        inSet[key]=false;
    }
    
    bool contains(int key) {
        return inSet[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */