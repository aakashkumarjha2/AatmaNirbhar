//https://leetcode.com/problems/top-k-frequent-elements/
/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        vector<int>v;
        std::priority_queue<std::pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>> >minheap;
        for(int i =0;i<nums.size();i++)
            map[nums[i]]++;
        for(auto i = map.begin();i!=map.end();i++)
        {
            minheap.push({i->second,i->first});
            if(minheap.size()>k)
                minheap.pop();
        }
        
        while(minheap.size()>0)
        {
            v.push_back(minheap.top().second);
            minheap.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};
