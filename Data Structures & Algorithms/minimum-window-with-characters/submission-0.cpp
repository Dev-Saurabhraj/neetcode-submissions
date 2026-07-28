class Solution {
public:
    string minWindow(string s, string t) {
        int len_s = s.size();
        int len_t = t.size();

        unordered_map<char, int> mp;

        for(char c : t){
            mp[c]++;
        }
        int j = 0;
        int start = 0;
        int minLen = INT_MAX;
        int required = len_t;
        for(int i = 0; i<len_s; i++){
           char c = s[i];
           if(mp[c] > 0) required--;

           mp[c]--;

           while(required==0){
            if(i - j +1 < minLen){

                minLen = i -j + 1;
                start = j;
            }

            mp[s[j]]++;

            if(mp[s[j]]>0) required++;
            j++;
           }
        }

    return minLen ==INT_MAX? "" : s.substr(start, minLen);
    }
};
