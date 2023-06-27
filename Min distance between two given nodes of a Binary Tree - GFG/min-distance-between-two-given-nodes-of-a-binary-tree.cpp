//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    
     int distanceBetweenNODES(Node*root , int numx)
    {
        if(!root)
        {   
            return 0 ;
        }
        if(root->data== numx)
        {
            return 1;
        }
        int a = distanceBetweenNODES(root->left , numx);
        int b = distanceBetweenNODES(root->right , numx);
        
        if(!a and !b)return 0 ;
        return a+b+1;
    }
        Node* LCA(Node* root ,int n1 ,int n2 )
    {
    		if(!root)
        	{
        		return NULL;
        	}
        	if(root->data==n1 || root->data==n2)
        	{
        		return root ;
        	}
        	Node*l = LCA(root->left , n1 , n2);
        	Node*r = LCA(root->right , n1 , n2);
        	
        	if(l and r)return root ;
        	if(l)return l ;
        	else return r; 
    }
    int findDist(Node* root, int a, int b) 
    {
       return  distanceBetweenNODES(LCA(root, a , b) , a)+distanceBetweenNODES(LCA(root, a , b) , b)-2;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends