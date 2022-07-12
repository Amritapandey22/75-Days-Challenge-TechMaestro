// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int num[], int n, int k)
    {
        //code here.
        unordered_map<int,int>mp;
        vector<int>ans;
        int i=0,j=0;
        while(j<n){
            mp[num[j]]++;
           
            if(j-i==k-1){
                ans.push_back(mp.size());
                
                if(mp[num[i]]>1)mp[num[i]]--;
                
                else mp.erase(num[i]);
                i+=1;
            }
           j+=1;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends