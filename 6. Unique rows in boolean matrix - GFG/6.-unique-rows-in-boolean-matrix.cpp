// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/
int retXor(string num){
    int n=stoi(num);
    return n^1;
}
vector<vector<int>> uniqueRow(int m[MAX][MAX],int row,int col)
{
//Your code here
      unordered_set<int>st;
      vector<vector<int>>ans;
      
      for(int i=0;i<row;i++){
          vector<int>temp;
          string num="";
          for(int j=0;j<col;j++){
              num+=to_string(m[i][j]);
              temp.push_back(m[i][j]);
          }
          
          int val=retXor(num);
          if(st.find(val)==st.end()){
             ans.push_back(temp); 
          }
          st.insert(val);
      }
      
      return ans;
}