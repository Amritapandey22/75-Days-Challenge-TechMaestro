// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool checkCol(int color,bool graph[101][101],int node,vector<int>&clr,int n){
    for(int i=0;i<n;i++){
        if(i!=node and graph[i][node] == true and clr[i]==color)return false;
    }
    return true;
}
bool solve(bool graph[101][101], int m, int n,vector<int>&clr,int node){
    if(node==n){
        return true;
    }
    
    for(int i=1;i<=m;i++){
        if(checkCol(i,graph,node,clr,n)){
            clr[node]=i;
            if(solve(graph,m,n,clr,node+1))return true;
            clr[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int>clr(n,0);
    if(solve(graph,m,n,clr,0))return true;
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends