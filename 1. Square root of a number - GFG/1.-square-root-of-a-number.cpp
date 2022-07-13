// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    #define lli long long int 
long long int floorSqrt(long long int x) 
{
    // Your code goes here 
    
    lli l=1,r=x;
    int ans=0;
    
    while(l<=r){
        lli mid=(l+(r-l)/2);
        if(mid*mid==x)return mid;
        else if(mid*mid>x){
            r=mid-1;
        }
        else{
            ans=mid;
            l=mid+1;
        }
    }
    return ans;
}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends