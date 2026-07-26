class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int j = 0;
        int ans = 0;

        for(int i = 0; i<n; i++){
            char c = s[i];
            if(mp.find(c)!=mp.end()){
                while(j<=mp[c]){
                    mp.erase(s[j]);
                    j++;
                }
            }
            mp[c] = i;
            ans = max(i-j+1, ans);
        }
        return ans;
    }
};
