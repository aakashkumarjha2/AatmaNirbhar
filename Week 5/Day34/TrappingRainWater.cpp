//https://leetcode.com/problems/trapping-rain-water/
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0,current=0;
        stack<int>st;
        while(current<height.size())
        {
            while(!st.empty() && height[current]>height[st.top()])
            {
                int top = st.top();
                st.pop();
                if(st.empty())
                    break;
                int distance = current - st.top()-1;
                int bounded_height = min(height[current],height[st.top()])-height[top];
                ans+=distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};

/*
Time complexity: O(n)O(n).
Single iteration of O(n)O(n) in which each bar can be touched at most twice(due to insertion and deletion from stack) and insertion and deletion from stack takes O(1)O(1) time.
Space complexity: O(n)O(n). Stack can take upto O(n)O(n) space in case of stairs-like or flat structure.

*/