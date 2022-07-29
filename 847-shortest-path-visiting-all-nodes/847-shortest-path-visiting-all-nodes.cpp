class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int finalState=(1<<n)-1;
        //this will give signify all nodes visted
        queue<vector<int>>q;
        //for bfs
        set<pair<int,int>>st;
        //currnode,bitmasked state
        /// no vis array becz "revisit nodes multiple times, and you may reuse edges."
        for(int i=0;i<n;i++){
            int mask=(1<<i);//mask created;
            q.push({i,mask,0});//bcz we may receive shortest path via any node
            st.insert({i,mask});
            
        }
        //we are using bitmasking coz it can give us the sequence of nodes inserted like
        //0-> mask 0001,1->0011, 3->1011
        //whereas if we consisder set it won't give seq , like 0->1 then again 0->1-> not possible but we need this 
        //in bit mask 0->1 will form a mask and is stored if again 0>1 happens set will not let that happen
     
        while(q.size()){
         
                auto nodeinfo=q.front();
                q.pop();
                int nd=nodeinfo[0];
                int maskedState=nodeinfo[1];
                int level=nodeinfo[2];
                //cout<<nd<<endl;
                if(maskedState==finalState)return nodeinfo[2];
                for(auto &it:graph[nd]){
                    int newMask=maskedState|(1<<it);
                    if(st.find({it,newMask})==st.end()){
                        //does not exists
                        q.push({it,newMask,level+1});
                        st.insert({it,newMask});
                    }
                }
                
            
           
        }
        
        return -1;
    }
};