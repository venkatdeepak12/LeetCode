/*

Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Input:
First-line consists of T test cases. The first line of every test case consists of N, denoting the number of elements in the array. 
The second and third line of every test case consists of Inorder and preorder traversal of a tree.

Output:
For each test case, print the postorder traversal in a new line.

User Task:
Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n)
and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically.

Example:
Input:
2
4
1 6 8 7
1 6 7 8
6
3 1 4 0 5 2
0 1 3 4 2 5

Output:
8 7 6 1
3 4 1 5 2 0

Explanation:
Test Case 2: Tree constructed from given traversals will be:
                                                                      0
                                                                   /      \
                                                                 1         2
                                                               /     \      /
                                                             3       4   5

*/

//Code:

int v;   //global variable
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
    v++;
    root->left=tree(in,ij,r-1,pre,n);
    root->right=tree(in,r+1,ins,pre,n);
    return root;
}
Node* buildTree(int in[],int pre[], int n)
{
    v=0;   //always assign to zero as it is a global varialble
    return tree(in,0,n-1,pre,n);
}
