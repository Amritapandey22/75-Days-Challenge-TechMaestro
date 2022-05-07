class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(st.empty()==false and st.top()==s[i])st.pop();
            else st.push(s[i]);
        }
        
        s="";
        while(st.size()!=0){
            s+=st.top();
            st.pop();
        }
        
        reverse(s.begin(),s.end());
        return s;
    }
};