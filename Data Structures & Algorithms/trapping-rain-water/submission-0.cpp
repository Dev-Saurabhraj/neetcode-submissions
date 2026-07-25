class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0];
        vector<int> suffix(n, 0);
        vector<int> prefix(n, 0);

        for(int i = 0; i<n; i++){
            if(lmax < height[i]){
                lmax = height[i];
            }
                prefix[i] = lmax;
        }
        lmax = height[n-1];
        for(int i = n-1; i>=0; i--){
            if(lmax < height[i]){
                lmax = height[i];
            }
                suffix[i] = lmax;

        }
        lmax = 0;
        for(int i = 0; i<n; i++){
            lmax+= (min(prefix[i], suffix[i]) - height[i]);
        }
        return lmax;
    }
};
