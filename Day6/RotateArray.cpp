/*
https://leetcode.com/problems/rotate-array/

Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/


class Solution {
public:
    
    void reverse(vector<int>&nums,int start,int end)
    {
        while(start<end)
            swap(nums[start++],nums[end--]);
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1)
            return;
        reverse(nums,0,n-1);
        if(k>n)
            k = k-n;
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
        
    }
};
