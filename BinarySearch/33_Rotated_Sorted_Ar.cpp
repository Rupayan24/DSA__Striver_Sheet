/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
*/

/*
------Approach-------
1)It is a rotated sorted array [123456789] ---> [789123456] so, 7 to 9 is sorted abd 1 to 6 is sorted.

2)Now we need to identify which part of the array is sorted


3)If the element is directly found, return mid

4)If it is not directly found and if a[low] <= a[mid] ----> left part is sorted
  
  a)If target is also present btw low and mid such that a[low] <= target && target <= a[mid]
  b)Eliminate the right search space --> high = mid - 1;
  c)ELSE Eliminate left search space as target is not present in left sorted part --> low = mid + 1

5)If it is not directly found and if a[mid] <= a[high] ----> right part is sorted ** ** Dont write this statement as it is already in  a else statement for  left sorted part
  
  a)If target is also present btw mid and high such that a[mid] <= target && target <= a[high] 
  b)Eliminate the left search space --> low = mid + 1;
  c)ELSE Eliminate right search space as target is not present in right sorted part --> high = mid - 1


6) If the target element is not found in the array return -1.
*/


/*
--------Code----------
class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n = nums.size();
       int low = 0;
       int high  = n - 1; 

       while(low <= high)
       {
        int mid = low + ((high - low) / 2);

        if(nums[mid] == target)
        {
            return mid;
        }

        else if(nums[low] <= nums[mid]) // Left Sorted
        {
            if(nums[low] <= target  && target <= nums[mid]) // Target is also in Left sorted search space
            {
                high = mid - 1; // Eliminate the right search space
            }

            else
            {
                low  = mid + 1; // Eliminate left space as target is not present there
            }
        }

        else // Right Sorted
        {
            if(nums[mid] <= target  && target <= nums[high]) // Target is in right sorted search space
            {
                low = mid + 1; // Eliminate the left search space
            }

            else
            {
                high = mid - 1; // Eliminate the right search space
            }
        }
       }

       return -1; // If target element is not found
    }
};

*/

// TC = O(logn)
// SC = O(1)