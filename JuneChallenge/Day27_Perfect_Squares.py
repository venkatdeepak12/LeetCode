'''
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

'''
#Code:

class Solution:
    def numSquares(self, n: int) -> int:
        
        arr, i = [], 1
        while i**2 <= n:
            arr.append(i**2)
            i += 1
        if n in arr:
            return 1
        for e in arr:
            if n-e in arr:
                return 2
        
        arr_set = set(arr)
        for i in range(len(arr)):
            for j in range(len(arr)):
                if n-arr[i]-arr[j] in arr_set:
                    return 3
        
       
        return 4
        
