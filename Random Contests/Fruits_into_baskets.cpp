/*

In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?

 

Example 1:

Input: [1,2,1]
Output: 3
Explanation: We can collect [1,2,1].


Example 2:

Input: [0,1,2,2]
Output: 3
Explanation: We can collect [1,2,2].
If we started at the first tree, we would only collect [0, 1].


Example 3:

Input: [1,2,3,2,2]
Output: 4
Explanation: We can collect [2,3,2,2].
If we started at the first tree, we would only collect [1, 2].


Example 4:

Input: [3,3,3,1,2,1,1,2,3,3,4]
Output: 5
Explanation: We can collect [1,2,1,1,2].
If we started at the first tree or the eighth tree, we would only collect 4 fruits.


*/

//Code:

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        queue<int> q;
        int i=0,first=-1,second=-1,len,maxlen=INT_MIN,n;
        n=tree.size();
        while(i<n)
        {
            int curr=tree[i];     //current element
            if(first==-1)
            {
                first=curr;    // assigning first element
            }
            else if(curr!=first and second==-1)
            {
                second=curr;     // assigning second element
            }  
            if(curr==first || curr==second)
            {
                q.push(curr);    //  if the window contains only first and second elements only then push current element
            }
            else
            {
                int f=0,s=0;
                while(!q.empty())
                { 
                    if(q.front()==first)
                    {
                        s=0;
                        f++;   // counting the consecutive first elements which are at last of our window
                    }
                    else
                    {
                        s++;    // counting the consecutive second elements which are at last of our window
                        f=0;
                    }
                     q.pop();
                }
                int h=f;
                if(s)
                {
                    first=second;   //if second element is repeating assign to first
                    h=s;
                }
                while(h)
                {
                    q.push(first);    //inserting the consecutive repeated elements into our queue
                    h--;
                }
                second=curr;      //assign new element as second
                q.push(curr);
            }
            len=q.size();
            if(len>maxlen)
            {
                maxlen=len;  //update max lenght
            }
           i++; 
        }
        return maxlen;  
    }
};
