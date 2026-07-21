class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                int minbar = min(heights[i], heights[j]);
                ans = max(ans, minbar*(j-i));
            }
        }
        cout<<ans;
        return ans;
    }
};
