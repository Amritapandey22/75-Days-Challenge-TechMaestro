class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int>q;
        q.push(0);
        vector<bool>vis(n,false);
        vis[0]=true;
        int cnt=1;
        while(q.size()){
            int node=q.front();
            q.pop();
            for(int el:rooms[node]){
                if(!vis[el]){
                    vis[el]=true;
                    cnt+=1;
                    q.push(el);
                }
            }
        }
        
        return cnt==n;
    }
};