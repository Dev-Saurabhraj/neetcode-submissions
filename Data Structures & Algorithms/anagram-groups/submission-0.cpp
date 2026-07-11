class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(string str : strs){
            string tempstr = str;
            sort(str.begin(), str.end());
            mp[str].push_back(tempstr);
        }

        for(auto it : mp){
            vector<string> temp;
            for(string s : it.second){
                temp.push_back(s);
            }
            res.push_back(temp);
        }
        return res;
    }
};
