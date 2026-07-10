class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int start = 0;
        int end = 0;
        vector<int> res;
        for(int i = 0 ;i <nums.size(); i++){

            int n = nums[i];

            int rem = target - n;

            if(mp.find(rem)!=mp.end()){
                start = mp[rem];
                end  = i;
                break;
            }
            mp[n] = i;
        }
        res.push_back(start);
        res.push_back(end);

        return res;
    }
};
