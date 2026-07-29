class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans;
        for(int i = 0; i<n ; i++){
            int j ;
            for( j = i+1; j<n; j++){
                if(temp[j]>temp[i] ){
                    ans.push_back(j-i);
                    break;
                }
            }
            if(j==n) ans.push_back(0);
        }
        return ans;
    }
};
