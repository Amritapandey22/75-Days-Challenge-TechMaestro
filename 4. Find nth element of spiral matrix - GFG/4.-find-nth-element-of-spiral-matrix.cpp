// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int [MAX][MAX],int ,int ,int );
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<findK(a,n,m,k)<<endl;
        
       
    }
}// } Driver Code Ends


/*You are required to complete this method*/
    int findK(int A[MAX][MAX], int n, int m, int k)
    {
    //Your code here
      int count=0;
      int minr=0;
      int minc=0;
      int maxr=n-1;
      int maxc=m-1;
      
      while(minr<=maxr and minc<=maxc and count!=m*n){
          for(int i=minc;i<=maxc;i++){
              if(++count==k)return A[minr][i];
          }
          minr++;
          
          for(int i=minr;i<=maxr;i++){
              if(++count==k)return A[i][maxc];
          }
          maxc--;
          
          for(int i=maxc;i>=minc;i--){
              if(++count==k)return A[maxr][i];
          }
          maxr--;
          
          for(int i=maxr;i>=minr;i--){
              if(++count==k)return A[i][minc];
          }
          minc--;
      }
      
      return 0;
    
    }

