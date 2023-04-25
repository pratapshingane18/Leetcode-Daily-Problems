class SmallestInfiniteSet {
public:

    set<int> s;
    SmallestInfiniteSet() {
        for(int i =1; i < 1005; i++){
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int top = *s.begin();
        s.erase(s.begin());
        return top;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

