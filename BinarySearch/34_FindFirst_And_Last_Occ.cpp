/*

34)Find First and Last Position of Element in Sorted Array
----------------------------------------------------------






Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

/*
Solution Hint


step-1--(Finding algo)
1)Sorted in non-decreasing order --> probable binary search
2)algo --> O(logn) --> binary search

Step-2--(Approach)


1)arr[] = [5,7,7,8,8,10] , target = 8
2)starting index will be 3
3)ending index will be 4

4)Here we can use lower bound & upper bound technique to solve the problem
5)Starting index will be lower bound as arr[mid] >= target i.e it finds the first index
6)Ending index will be (upper bound - 1) as upperbound = (arr[mid] > target), upperbound finds just the next largest element, so to find the last occurence of the target element, we need to do upperbound - 1

step-3--(Finding edgecases)

1)if lowerbound == size of array, then we are not getting lowerbound and upperbound indexes, so return {-1,-1}
2)if arr[lowerbound] != target, i.e target is not present in the array, then also we are not getting lowerbound and upperbound indexes, so return {-1,-1}

step-4--(Solution strategy)
1)At first make a function to find the lowebound
2)Then make a function to find the upperbound
3)Make a function to return two indexes(lowerbound & upperbound)


*/


/*

-------------CODE---------------------


class Solution {
public:
    // Lowerbound
    int lower_bound(vector<int> &nums, int target, int n)
    {
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }

    // Upperbound

    int upper_bound(vector<int> &nums, int target, int n)
    {
        int low = 0;
        int high = n - 1;
        int ans = n;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] > target)
            {
                ans = mid;
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       int n = nums.size();
       vector<int> result(2,-1);
       int first = lower_bound(nums, target, n);
       if((first == n) || (nums[first] != target))
       {
              return {-1,-1};
       }

       int last = upper_bound(nums, target, n) - 1;
       result[0] = first;
       result[1] = last;
       return result;
    }
};

// TC = O(logn)
// SC = O(1)

*/