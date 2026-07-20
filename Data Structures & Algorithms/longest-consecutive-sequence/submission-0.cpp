class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> mp;
         for(int i :nums){
            mp.insert(i);
         }
         int start = 0;
         int end = 0;
        for(auto &it : mp){
            start = end = it;

            while(mp.find(start-1)!= mp.end()){
                start--;
            }
            while(mp.find(end+1)!= mp.end()){
                end++;
            }
            ans = max(ans, end-start+1);

        }
        return ans;

    }
};
