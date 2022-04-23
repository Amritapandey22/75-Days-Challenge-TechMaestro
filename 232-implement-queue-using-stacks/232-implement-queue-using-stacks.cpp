class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int>ip,op;
    
    void push(int x) {
        ip.push(x);//O(1) complexity
    }
    
    int pop() {
        int x=0;
        if(op.size()!=0){
             x=op.top();
            op.pop();
            
        }else{
            while(ip.size()!=0){
                op.push(ip.top());
                ip.pop();
            }
            
             x=op.top();
             op.pop();
            
        }
        
        return x;
    }
    
    int peek() {
        if(op.size()!=0){
             return op.top();
            //op.pop();
            
        }else{
            while(ip.size()!=0){
                op.push(ip.top());
                ip.pop();
            }
            
             return op.top();
             //op.pop();
            
        }
        
    }
    
    bool empty() {
         while(ip.size()!=0){
                op.push(ip.top());
                ip.pop();
            }
            
             return op.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */