class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> mp;
         for(int i :nums){
            mp.insert(i);
         }
        for(auto &it : mp){
         if(mp.find(it-1)==mp.end()){
            int curr = it;
            int temp = 1;

            while(mp.count(curr+1)){
                curr++;
                temp++;
            }
            ans = max(ans, temp);
         }
        }
        return ans;

    }
};
