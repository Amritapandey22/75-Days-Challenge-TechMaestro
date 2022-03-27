class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intrvl) {
        sort(intrvl.begin(),intrvl.end());
        
        if(intrvl.size()==0)return {};
        vector<vector<int>>mergedInt;
        vector<int>tempInt=intrvl[0];
        for(auto it:intrvl){
            if(it[0]<=tempInt[1]){
               tempInt[1]=max(it[1],tempInt[1]);  
            }else{
                mergedInt.push_back(tempInt);
                tempInt=it;
            }
        }
        mergedInt.push_back(tempInt);
        return mergedInt;
        
    }
};