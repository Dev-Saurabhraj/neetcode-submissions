class Solution {
public:
    bool isAnagram(string s, string t) {

        vector<int> freq(26, 0);
        vector<int> freqt(26, 0);
        for(char c : s){
            freq[c-'a']++;
        }
        for(char c : t){
            freqt[c-'a']++;
        }
        return freq == freqt;
        
    }
};
