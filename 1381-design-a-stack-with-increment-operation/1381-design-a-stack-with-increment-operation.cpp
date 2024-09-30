class CustomStack {
public:
    vector<int> st;
    int n;
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(st.size() < n){
            st.push_back(x);
        }
    }
    
    int pop() {
        if(st.size() != 0){
            int x = st[st.size() - 1];
            st.pop_back();
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int a;
        if(k <= st.size()) a = k;
        else a = st.size();
        for(int i = 0; i < a;i++){
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */