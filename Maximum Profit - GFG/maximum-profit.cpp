// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(2,vector<int>(K+1,0)));
        
        for(int idx=N-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int trans=1;trans<=K;trans++){
                      if(buy){
                              dp[idx][buy][trans]= max(-A[idx]+dp[idx+1][0][trans],dp[idx+1][1][trans]);
                          }
                         else dp[idx][buy][trans]=max(A[idx]+dp[idx+1][1][trans-1],dp[idx+1][0][trans]);
                }
            }
        }
        
        return dp[0][1][K];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends