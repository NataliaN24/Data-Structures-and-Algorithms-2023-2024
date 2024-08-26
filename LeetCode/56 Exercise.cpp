class MyHashSet {
private:
static const int bucketsCount=1000;
vector<list<int>>table;
int hash(int key)const{
    return key%bucketsCount;
}
public:
    MyHashSet():table(bucketsCount) {
        
    }
    
    void add(int key) {
        int index=hash(key);
        for(const int&val:table[index])
        {
            if(val==key){
                return;
            }
        }
        table[index].push_back(key);
    }
    
    void remove(int key) {
        int index=hash(key);
        auto&list=table[index];
        list.remove(key);
    }
    
    bool contains(int key) {
        int index=hash(key);
        for(const int&val:table[index])
        {
            if(val==key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
