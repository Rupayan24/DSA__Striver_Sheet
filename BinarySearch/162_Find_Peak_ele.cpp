/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.

*/


/*
---Brute Force ---
The most easy solution for this problem is that we can do a linear search for finding the element such that nums[i] > nums[i-1]  && nums[i] > nums[i+1]

But this approach is going to take TC - O(n)


So, we need to optimize it.
---Hints---
Now the problem says ---> Find Peak Element
Find means searching
According to the question, we need to solve this in O(logn)


For an element being peak, its left side element needs to be smaller(comes as increasing order) and the right side element must be smaller(comes in decreasing order)

Hence it looks like 

        element(peak)
     /                \
    /                   \
left(increasing)          right(decreasing)

So,we can think that binary search might work here.

---Edge Cases---
As this question contains a binary search and it also needs to see about nums[mid],nums[mid-1] ----> i.e left of mid  and nums[mid+1] ----> i.e right of mid

According to the question, nums[-1] = -infinity and nums[n] = -infinity

So,we need to find edge cases first
1) If the size of nums is 1 
example- nums[] = [3]
here 3 is the peak element because nums[] = -infinity,[3],-infinity  --->index = -1,0,1(n)
Here nums[mid] (3) > nums[mid-1] ( -infinity) && nums[mid] (3) > nums[mid+1] ( -infinity)
Thus it becomes the peak element

2)If nums[0] > nums[1] then we can say that nums[0] is peak as nums[-1] is already -infinity
3)If nums[n-1] > nums[n-2] then we can say that nums[n-1] is peak as nums[n] is already -infinity

So, this are the edge cases.Eliminiting this, we can trim down the search space.

---Approach---

After trimming down we can say,
low = 1;
high = n-2;

Now we can use the typical binary search

if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid

else if(nums[mid] > nums[mid-1])  the left half is increasingly sorted and the right element is more larger(i.e. it can be the peak), so we need to eliminate the left half.
----> low = mid + 1

else
----> high = mid - 1   (in this case the right side is sorted in decreasing order i.e. the left most element is the largest(i.e. maybe it can be peak), so we should eliminate the right search space)


At the end, return -1 as the dummt statement as the function requires a return statement


TC = O(logn)
SC = O(1)
*/

/*---code
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n  == 1) return 0;

        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;


        int low = 1;
        int high = n - 2;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[mid - 1]  && nums[mid] > nums[mid + 1])
            {
                return mid;
            }

            else if(nums[mid - 1] > nums[mid])
            {
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }

        return -1;
    }
};

*/