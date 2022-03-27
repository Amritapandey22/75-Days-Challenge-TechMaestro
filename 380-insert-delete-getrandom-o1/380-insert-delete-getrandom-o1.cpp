#define pb push_back
class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>nums;
    RandomizedSet() {
        
    }    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        
        mp[val]=nums.size();
        nums.pb(val);
        
        return true;
    }    
    bool remove(int val) {
        if(mp.find(val)==mp.end())return false;
        int remidx=mp[val];
        mp.erase(val);
        if(remidx==nums.size()-1){
            nums.pop_back();
            return true;
        }
        swap(nums[remidx],nums[nums.size()-1]);
        //int nval=nums[nums.size()-1];
        mp[nums[remidx]]=remidx;
        nums.pop_back();
        return true;
        
    }    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

