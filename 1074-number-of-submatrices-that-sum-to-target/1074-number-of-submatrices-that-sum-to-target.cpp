class Solution {
public:
    int f(vector<int> & v,int t){
        int n=v.size(),sum=0,ans=0;
        unordered_map<int,int>m;
        m[0]=1;
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(m.count(sum-t))ans+=m[sum-t];
            m[sum]++;
        }
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& mt, int trg) {
        int n=mt.size();
        int m=mt[0].size(),ans=0;
        
        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=i;j<n;j++){
                for(int k=0;k<m;k++)temp[k]+=mt[j][k];
                 ans+=f(temp,trg);                
            }
        }
        
        return ans;
    }
};