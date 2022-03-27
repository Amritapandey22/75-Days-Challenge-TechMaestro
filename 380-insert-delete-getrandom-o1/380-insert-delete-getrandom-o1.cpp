#define pb push_back
class RandomizedSet {
public:
    RandomizedSet() {
       
    }
    unordered_map<int,int>mp;
    vector<int>nums;
    int idx;
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        
        mp[val]=nums.size();
        
        nums.pb(val);
        
        return true;
        
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())return false;
        idx=mp[val];
        if(idx==nums.size()-1){
            nums.pop_back();
            mp.erase(val);
            return true;
        }
        swap(nums[idx],nums[nums.size()-1]);
        mp[nums[idx]]=idx;
        mp.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */