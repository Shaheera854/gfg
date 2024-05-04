//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node *BuildTree(int in_st,int in_en,int in[],int p_st,int p_en,int post[],map<int,int>&mpp){
    if(in_st>in_en or p_st>p_en)return NULL;
    Node* root=new Node(post[p_en]);
    int ind;
    for(auto it:mpp){
        if(it.second==root->data){
            ind=it.first;
            mpp.erase(it.first);
            break;
        }
    }
    int rem=ind-in_st;
    root->left=BuildTree(in_st,ind-1,in,p_st,p_st+rem-1,post,mpp);
    root->right=BuildTree(ind+1,in_en,in,p_st+rem,p_en-1,post,mpp);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    map<int,int>mpp;
    //if(sizeof(in)/sizeof(int)!=sizeof(post)/sizeof(int))return NULL
    for(int i=0;i<n;i++)mpp[i]=in[i];
    return BuildTree(0,n-1,in,0,n-1,post,mpp);
}
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends