class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= heights.size(); i++) {

            int currentHeight;

            if (i == heights.size()) {
                currentHeight = 0;
            } else {
                currentHeight = heights[i];
            }

            while (!st.empty() && heights[st.top()] > currentHeight) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                int area = height * width;
                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        return maxArea;
    }
};