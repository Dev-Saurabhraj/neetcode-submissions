class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> temp;
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i : nums){
            mp[i]++;
        }
        for(auto it : mp){
            temp.push_back({it.first, it.second});
        }
        sort(temp.begin(), temp.end(), [](auto &a, auto&b){
            return a.second > b.second;
        });

        for(int i = 0; i<k; i++){
            res.push_back(temp[i].first);
        }
        return res;
    }
};
