/*

Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.

Example:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8

*/

//Code:

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int x;
    KthLargest(int k, vector<int>& nums) {
        int i;
        x=k;
        for(i=0;i<k && i < nums.size();i++)
        {
            pq.push(nums[i]);
        }
        for(i=k;i<nums.size();i++)
        {
           if(nums[i]>pq.top())
           {
               pq.pop();
               pq.push(nums[i]);
           }
            
        }
     
    }
    
    int add(int val) {
        if(x>pq.size()) 
        {
            pq.push(val);
        }
        else if(val>pq.top())
        {
            pq.pop();
            pq.push(val);
            
        }
        if(pq.size()) return pq.top();
        return -1;
    }
};
