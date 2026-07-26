class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int j = 0;
        int ans = 0;
        int maxfeq =0;
        unordered_map<char, int> mp;
        for(int i = 0; i<n; i++){
            mp[s[i]]++;
            maxfeq = max(maxfeq, mp[s[i]]);
            while((i-j+1) - maxfeq > k){
                mp[s[j]]--;
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};   
