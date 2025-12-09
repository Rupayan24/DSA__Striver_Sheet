/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
 

Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?



-------Hints------
1)Array is in Non-decreasing order ----> Binary Search might work




-------Approach------
Step - 1)At first think that the problem only contains unique elements and try to solve it as that of Rotated Sorted Array I
Step - 2)Now think of the edge cases where our solution is failing
Step - 3)Now try to fix the edge cases


-------Algorithm--------
Step - 1)If arr[mid] == target then the element is present in the array, so return true
Step - 2)If arr[low] == arr[mid] && arr[mid] == arr[high] then this is a case of containing duplicate elements

            ex:-
            arr[] = [3(0) 1(1) 2(2) 3(3) 3(4) 3(5) 3(6)]    Order :- value(index)

         
So,in this case, we cant find directly which part is sorted as arr[low] == arr[mid] && arr[mid] == arr[high]

a)Hence we need to trim down the array until either arr[low] != arr[mid] or arr[mid] != arr[high]

b)We need to continue this till (arr[low] == arr[mid] && arr[mid] == arr[high]) condition becomes false so, low++, high--, continue;

Step - 3)Now as (arr[low] == arr[mid] && arr[mid] == arr[high]) condition becomes false
So, we can go with the simple binary search algorithm

Step -4)If arr[low] <= arr[mid] i.e left half is sorted then
a) If (arr[low] <= target && target <= arr[mid]) == true i.e the target element is present is the sorted half so, we can easily do binary search in that half and can get the target. So, we dont need the right half so we can eliminate the right half (high = mid - 1)

b) If (arr[low] <= target && target <= arr[mid])  == false i.e the target element is absent, so we dont need the left sorted space anymore hence we can eliminate it (low = mid + 1)

Step -5)If (arr[low] <= arr[mid]) == false i.e right half is sorted then
a) If (arr[mid] <= target && target <= arr[high]) == true i.e the target element is present in the sorted half so, we can easily do binary search in that half and can get the target. So, we dont need the right half so we can eliminate the left half (low = mid + 1)

b) If (arr[low] <= target && target <= arr[mid])  == false i.e the target element is absent, so we dont need the right sorted space anymore hence we can eliminate it (high = mid - 1)

Step - 6)If the target element is found in the array then it will return true or else false
*/

/*
------Code-------

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while(low <= high)
        {
            int mid = low + ((high - low) / 2);

            if(nums[mid] == target)
            {
                return true;
            }

            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }

            if(nums[low] <= nums[mid]) // Left half sorted
            {
                if(nums[low] <= target && target <= nums[mid]) // Is target in the left sorted half
                {
                    high = mid - 1; // If true then eliminate the right half
                }

                else
                {
                    low = mid + 1; // If false then eliminate the left half
                }
            }

            else // Right half sorted
            {
                if(nums[mid] <= target && target <= nums[high]) // Is target in right sorted half
                {
                    low = mid + 1; // If true then eliminate the left half
                }

                else
                {
                    high = mid - 1; // If false then eliminate the right half
                }
            }
        }
        return false;
    }
};

*/

// TC = O(logn)
// SC = O(1)