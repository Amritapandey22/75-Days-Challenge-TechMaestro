class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& adj) {
        
        queue<int>q;
	    vector<int>indeg(n,0);
        vector<vector<int>>grph(n);
	    for(auto it:adj){
            grph[it[1]].push_back(it[0]);
	        indeg[it[0]]+=1;
	    }
	    for(int i=0;i<n;i++){
	        if(indeg[i]==0)q.push(i);
	    }
	    vector<int>ans;
	    while(q.size()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it:grph[node]){
	            if(--indeg[it]==0)q.push(it);
	        }
	    }
	    
	    if(ans.size()==n)return true;
	    return false;
    }
};