class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= len; i++) {
            int curr;
            if (i == len) curr = 0;
            else curr = heights[i];

            while (!st.empty() && curr < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;
                maxArea = max(maxArea, width * height);
            }

            st.push(i);
        }

        return maxArea;
    }
};