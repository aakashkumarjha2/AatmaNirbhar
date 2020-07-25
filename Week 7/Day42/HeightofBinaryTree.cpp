//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
/*
Given a binary tree, find its height.

Input:
First line of input contains the number of test cases T. For each test case, there will be only one single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each testcase, in a new line, print the height of tree.

Your Task:
You don't need to read input or print anything. Your task is to complete the function height() that takes root Node of the Tree as input and returns the Height of the Tree. If the Tree is empty, return 0. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 105
1 <= Data of a node <= 105
Sum of N over all testcases doesn't exceed 105

Example:
Sample Input:
3
1 2 3
2 N 1 3 N
10 20 30 40 60 N N

Sample Output:
2
3
3

Explanation:
Testcase1: The tree is
        1
     /      \
   2        3
So, the height would be 2.

Testcase2: The tree is
                           2
                              \
                               1 
                              /    
                          3
So, height would be 3.

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int height(struct Node* node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<height(root)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// return the Height of the given Binary Tree
int height(Node* root)
{
   // Your code here
   int count=0;
   if(root==NULL)
   return 0;
   
   count = max(height(root->left),height(root->right))+1;
   
   return count;
}

