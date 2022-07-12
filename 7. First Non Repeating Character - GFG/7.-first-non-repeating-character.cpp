// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

string find(string s);

//Your code will be place here

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int x;
	    cin >> x;
	    string s;
	    cin >> s;
	    int h[26];
	    
	    cout << find(s) << "\n";
	    
	}
	
	return 0;
}// } Driver Code Ends


//User function template for C++

// return the first non-repeating char in S.
// if there's no non-repeating char, return "-1"
string find(string S) {
    //code here
    unordered_map<char,int>mp;
    
    for(char ch:S)mp[ch]++;
    
    for(char ch:S){
        if(mp[ch]==1){
        string ans="";
        ans+=ch;
        return ans;
    }
  }    
    return "-1";
}