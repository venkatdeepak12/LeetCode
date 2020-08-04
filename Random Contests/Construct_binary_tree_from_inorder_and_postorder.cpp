/*

Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. 
The task is to construct the binary tree from these traversals.
For example, if given inorder and postorder traversals are {4, 8, 2, 5, 1, 6, 3, 7} and {8, 4, 5, 2, 6, 7, 3, 1}
respectively, then your function should construct below tree.

          1
       /      \
     2        3
   /    \     /   \
  4     5   6    7
    \
      8

Input:
First line of input contains number of testcases T. For each testcase, 
first line of input contains number of nodes in the tree, and next two lines contains inorder and postorder respectively.

Output:
For each testcase, print the preorder traversal of tree.

Your Task:
Complete the function buildTree() which takes the inorder, 
postorder traversals and the number of nodes in the tree as inputs and returns the root node of the newly constructed Binary Tree.

Example:
Input:
2
8
4 8 2 5 1 6 3 7
8 4 5 2 6 7 3 1
5
9 5 2 3 4
5 9 3 4 2
Output:
1 2 4 8 5 3 6 7
2 9 5 4 3

Explanation:
Testcase 1: For the given postorder and inorder traversal of tree the  resultant binary tree will be
          1
       /      \
     2        3
   /    \     /   \
  4     5   6    7
    \
      8
Testcase 2: For the given postorder and inorder traversal of tree the  resultant binary tree will be
               2
          /           \
        9            5
      /     \
    4      3

*/

//Code:

int v;    //global variable;
int search(int a[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            return i;
        }
    }
    return -1;
}

Node* tree(int in[],int ij,int ins,int pre[],int n)
{
    if(ij>ins) return NULL;
    Node *root=new Node(pre[v]);
    int r=search(in,n,pre[v]);
    v--;
    root->right=tree(in,r+1,ins,pre,n);    // as we are trvasering postorder backwards we need to fisrt insert right and then left (LRr order from backwards)..
    root->left=tree(in,ij,r-1,pre,n);
    
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    v=n-1;    //assign to last value and postorder root will be from last
    return tree(in,0,n-1,post,n);
}
