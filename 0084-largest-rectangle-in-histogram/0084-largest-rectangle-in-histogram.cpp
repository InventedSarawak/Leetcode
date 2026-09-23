class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= len; i++) {
            int curr = 0;
            if (i != len) curr = heights[i];

            while (!st.empty() && curr < heights[st.top()]) {
                int height = heights[st.top()];
                int width = i;
                st.pop();
                
                if (!st.empty()) width = i - st.top() - 1;
                maxArea = max(maxArea, width * height);
            }

            st.push(i);
        }

        return maxArea;
    }
};