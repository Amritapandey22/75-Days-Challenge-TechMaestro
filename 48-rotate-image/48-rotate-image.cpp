class Solution {
public:
    void reverse(vector<int>&arr){
        int l=0;
        int r=arr.size()-1;
        while(l<r){
            swap(arr[l++],arr[r--]);
        }
    }
    void rotate(vector<vector<int>>& mt) {
        //transpose + reverse 
        int n=mt.size();
        int m=mt[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i<=j){
                    swap(mt[i][j],mt[j][i]);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            reverse(mt[i]);
        }
    }
};