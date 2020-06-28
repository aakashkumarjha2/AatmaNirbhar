//https://leetcode.com/problems/repeated-dna-sequences/
/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>map;
        vector<string>ans;
        if(s.size()<10)
            return ans;
        
        for(int i = 0;i<s.size()-9;i++)
            map[s.substr(i,10)]++;
        
        for(auto it:map)
            if(it.second>1)
                ans.push_back(it.first);
        return ans;
    }
};
