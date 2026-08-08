class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        int area = 0;
        stack<int> st;

        for(int i = 0; i<=n; i++){

            int h = (i == n) ? 0 : heights[i];

            while(!st.empty() && h< heights[st.top()] ){
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                area = max(area, height*width);
            }
            st.push(i);
        }
        return area;
    }
};
