class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int m = s1.size();
        if(m>n) return false;
        vector<int> p1(26, 0);

        vector<int> p2(26, 0);

        for(int i = 0; i<m; i++){
            p1[s1[i]-'a']++;
            p2[s2[i]-'a']++;
        }

        for(int i = m, j = 0; i<n; i++, j++){
            if(p1==p2) return true;
            p2[s2[i]-'a']++;
            p2[s2[j]-'a']--;
        }

       return p1==p2;
    }
};