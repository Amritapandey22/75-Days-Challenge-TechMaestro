class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        int n=arr.size();
        queue<int>q;
        q.push(0);
        vector<bool>vis(n,false);
        int level=0;
        while(q.size()){
            int sz=q.size();
            while(sz--){
                int idx=q.front();
                vis[idx]=true;
                q.pop();
                //i-1
                if(idx==n-1)return level;
                if(idx-1>=0 and !vis[idx-1])q.push(idx-1);
                ///i+1 jump
                if(idx+1<n and !vis[idx+1])q.push(idx+1);
                
                //for same elements
                for(int smidx:mp[arr[idx]]){
                    if(!vis[smidx])q.push(smidx);
                }
                mp[arr[idx]].clear();
            }
            
            level+=1;
        }
        
        return n-1;
    }
};