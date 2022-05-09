class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.size()==0)
            return res;
        vector<string>pad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve("",0,digits,pad,res);
        return res;
        
    }
    void solve(string build,int i,string digits,vector<string>pad,vector<string>&res){
        if(i==digits.length()){
            res.push_back(build);
            return;
        }
        int d=digits[i]-'0';
        for(auto ch:pad[d]){
            solve(build+ch,i+1,digits,pad,res);
        }
        
        
    }
};