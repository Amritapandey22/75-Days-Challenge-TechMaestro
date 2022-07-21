class Solution {
public:
    long long maximumSubsequenceCount(string t, string pt) {
       
     long long int count1=1,count0=1,res1=0,res0=0;
        for(int i=0,j=t.size()-1;i<t.size(),j>=0;i++,j--){
            //i will check for char[0] at begin and j will for last
            if(t[i]==pt[1]){
                res0+=count0;
            }
            if(t[j]==pt[0])res1+=count1;
            
            count0+=t[i]==pt[0];
            count1+=t[j]==pt[1];
        }
        
        return max(res0,res1);
    }
};