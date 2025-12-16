/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
*/

/*
Brute Force -- 
for(i = 0; i < n; i++)
{
    if(a[i] != a[i-1] && a[i] != a[i+1])
    {
        return a[i];
    }
}

TC = O(n)

In this approacvh we are simply comparing the current element with its previous element and its next element.
As the array is sorted so either the previous element or the next element should be equal to the current element if there is any duplicate.
Else the element is single


Hint ---
As the array is sorted, So we can think of binary search which has O(logn) TC.

As in this binary search approach we are using previous element(left) , current element(mid) and next element(right), so we need to find some edge cases

Edge Cases --- 
1) If the array contains only one element, then it is single element so return it
2)As nums[0] is the leftmost element so it has no previous element thus it becomes an edge case ---> So only one condition arises ---> if nums[0] != nums[1] then it becomes single element
3)Similarly nums[n-1] is the rightmost element, so it has no next element thus it becomes an edge case too ---> so only one condition arises ---> if nums[n-1] != nums[n-2] then it becomes single element


Approach---
After eliminating the edge cases, the array is trimmed down to --->
low = 1
high = n - 2

now we are going to use binary search

if((nums[mid] != nums[mid-1]) && (nums[mid] != nums[mid+1]))
then it is a single element ---> return nums[mid]

we are starting the array with index 0.
arr[] = [1-0 1-1 2-2 2-3 3-4 3-5 4-6 5-7 5-8 6-9 6-10]  --->nums[i]-i type showing

the single element here is 4 which is at index 6

if you see clearly it is at index 6---> so all the elements before it are in pairs ---> 
(0,1),(2,3),(4,5) 
and all the elements after it are also in pairs --->
(7,8),(9,10)

so from here on we can observe that 
before the single element
there will be a (even,odd) pair in the left side of single element
and
there will be a (odd,even) pair in the right side of single element

if((mid % 2 == 1 && nums[mid] == nums[mid-1]) or (mid % 2 == 0 && nums[mid] == nums[mid+1])) ---> I am on the left side of the single element, so i eliminate the left serach space.---> low = mid + 1

else
I am on the right side of the single element, so i eliminate the right serach space.---> high = mid - 1


at last return -1 // It is a dummy statement as the function should return something

*/

/*---Code---
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1;
        int high = n - 2;

        while(low <= high)
        {
            int mid = low + ((high - low) / 2);
            if((nums[mid] != nums[mid - 1]) && (nums[mid] != nums[mid + 1]))
            {
                return nums[mid];
            }

            else if((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums   [mid] == nums[mid + 1]))
            {
                low = mid + 1;
            }

            else
            {
                high = mid - 1;
            }
        }

        return -1;
    }
};

*/