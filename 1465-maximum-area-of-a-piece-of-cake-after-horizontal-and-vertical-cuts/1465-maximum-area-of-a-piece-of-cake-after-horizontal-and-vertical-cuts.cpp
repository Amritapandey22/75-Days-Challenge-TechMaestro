class Solution {
public:
    int mod=1e9+7;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
      
        int maxh=0;
        int maxv=0;
        
        hc.push_back(0);
        hc.push_back(h);
        
         vc.push_back(0);
         vc.push_back(w);   
        
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        
        for(int i=1;i<hc.size();i++){
            maxh=max(maxh,hc[i]-hc[i-1]);
            //cout<<hc[i]<<hc[i-1]<<endl;
        }
        
         for(int i=1;i<vc.size();i++){
            maxv=max(maxv,vc[i]-vc[i-1]);            
        }
        
        //unsigned long long int area=(maxh*maxv)%mod;
        return (long)maxh * maxv % 1000000007;;
    }
};