class Solution {
public:
    bool isValid(string s) {
        //int size=s.size();
        stack<char>st;
        for(char ch:s){
            if(ch=='(' or ch=='[' or ch=='{')st.push(ch);
            else{
                if(st.empty())return false;//matlab pehla char koi closing h,agar opening hota to upar waala catch kr leta
                if(ch==']' and st.top()!='[') return false;
                if(ch=='}' and st.top()!='{') return false;
                if(ch==')' and st.top()!='(') return false;
                
                st.pop();
            }
        }
        
        return st.empty();
    }
};