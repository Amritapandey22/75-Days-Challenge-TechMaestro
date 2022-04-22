class MyStack {
public:
    MyStack() {
        
    }
    queue<int>nums;
    
    void push(int x) {
        nums.push(x);
        int s=nums.size();
        for(int i=0;i<s-1;i++){
            nums.push(nums.front());
            nums.pop();
        }
    }
    
    int pop() {
        int a=nums.front();
        nums.pop();
        return a;
    }
    
    int top() {
        return nums.front();
    }
    
    bool empty() {
        return nums.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */