/*

Given an array w of positive integers, where w[i] describes the weight of index i, 
write a function pickIndex which randomly picks an index in proportion to its weight.

Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]



Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]

*/

//Code:

class Solution {
    private int[] cumSum;
    private int n;
    private Random rand;

    public Solution(int[] w) {
        n = w.length;
        cumSum = new int[n];
        rand = new Random();
        cumSum[0] = w[0];
        for (int i = 1; i < n; i++) 
        {
            cumSum[i] = cumSum[i - 1] + w[i];
        }
    }

    public int pickIndex() {
        int r = rand.nextInt(cumSum[n - 1]) + 1;
        int i = Arrays.binarySearch(cumSum, r);
        if (i < 0)
        {
            i = -(i + 1);
        }
        return i;
    }
}
