class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i<numbers.size(); i++){
            int curr = numbers[i];
            int comp = target - curr;
            if(mp.find(comp)!= mp.end()){
                ans.push_back(mp[comp]+1);
                ans.push_back(i+1);
                break;
            }
            mp[curr] = i;
        }
        return ans;
    }
};
