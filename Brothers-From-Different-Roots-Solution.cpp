**********************************************************************************  Question  ********************************************************************************************************************


Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.

Example 1:

Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8
BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18
x = 16
Output:
3
Explanation:
The pairs are: (5, 11), (6, 10) and (8, 8)
Example 2:

Input:
BST1:
  1
   \
    3
   /
  2
BST2:
    3
   / \
  2   4
 /     
1
x = 4
Output:
3
Explanation:
The pairs are: (2, 2), (3, 1) and (1, 3)
Your Task:
You don't need to read input or print anything. Your task is to complete the function countPairs(), which takes two BST's as parameter in the form of root1 and root2 and the integer x, that returns the count of all pairs from both the BSTs whose sum is equal to x.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106











*************************************************************************************  Solution  ******************************************************************************************************************
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:

  void count(Node* ptr , unordered_map<int,bool>&mp,int& ans,int& x){    
        int comp = x-ptr->data;
        if(mp[comp])++ans;
        if(ptr->left==nullptr&&ptr->right==nullptr)return;
        if(ptr->left)count(ptr->left,mp,ans,x);
        if(ptr->right)count(ptr->right,mp,ans,x);
    }
    
    void dfs(Node* ptr,unordered_map<int,bool>&mp ){
        mp[ptr->data]=true;
        if(ptr->left==nullptr&&ptr->right==nullptr)return;
        if(ptr->left)dfs(ptr->left,mp);
        if(ptr->right)dfs(ptr->right,mp);
    }
    
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        unordered_map<int,bool>mp;
        dfs(root1,mp);
        int ans=0;
        count(root2,mp,ans,x);
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}

// } Driver Code Ends
