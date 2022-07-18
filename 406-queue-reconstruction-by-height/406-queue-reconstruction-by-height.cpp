class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0])return a[0]>b[0];
        else return a[1]<b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        
        int n=people.size();
        vector<vector<int>>res;
        for(auto d:people){
            int idx=d[1];
            res.insert(res.begin()+idx, d);
        }
        
        return res;
    }
};