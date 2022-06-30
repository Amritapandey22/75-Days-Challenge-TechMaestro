class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& b, int ts) {
        long long ans=0;
        sort(b.begin(),b.end(),comp);
        
        for(auto d:b){
            
            int box=d[0];
            int units=d[1];
           
            if(ts-box>=0){
                 ts-=box;
                 ans+=(box*units);
            }else{
                ans+=(ts*units);
                return ans;
            }
           
        }
        
        return ans;
    }
};