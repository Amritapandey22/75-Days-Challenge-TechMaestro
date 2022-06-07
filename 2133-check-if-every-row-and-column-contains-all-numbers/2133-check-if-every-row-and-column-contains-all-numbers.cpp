class Solution {
public:
    bool checkValid(vector<vector<int>>& mt) {
        //for row
        string s="";
        
        int n=mt.size();
        for(int i=1;i<=n;i++)s+=to_string(i);
        sort(s.begin(),s.end());
        //cout<<s;
        //row check
        
        for(int i=0;i<n;i++){
            string tmp="";
            for(int j=0;j<n;j++){
               tmp+=to_string(mt[i][j]); 
            }
           
            sort(tmp.begin(),tmp.end());
             
            if(tmp!=s)return false;
            //cout<<tmp<<endl;
        }
        //col check
        for(int i=0;i<n;i++){
            string tmp="";
            for(int j=0;j<n;j++){
               tmp+=to_string(mt[j][i]); 
            }
            sort(tmp.begin(),tmp.end());
            if(tmp!=s)return false;
        }
        
        return true;
    }
};