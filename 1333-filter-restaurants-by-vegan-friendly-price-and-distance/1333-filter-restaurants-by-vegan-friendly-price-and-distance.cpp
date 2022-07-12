class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[1]==b[1])return a[0]>b[0];
        else return a[1]>b[1];
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>>veganRest;
       
            for(auto d:restaurants){
                if(d[2]==0 and veganFriendly)continue;
                if(d[3]>maxPrice)continue;
                if(d[4]>maxDistance)continue;
                
                veganRest.push_back(d);
            }
          restaurants=veganRest;  
        
        
        sort(restaurants.begin(),restaurants.end(),cmp);
        vector<int>ids;
        for(auto d:restaurants)ids.push_back(d[0]);
        
        return ids;
    }
};