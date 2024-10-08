class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;
        int pivot = -1;

        // Find the pivot (maximum element in rotated array)
        while (s <= e) {
            int mid = s + (e - s) / 2;

            // Check if the middle element is the pivot
            if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
                pivot = mid;
                break;
            }
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                pivot = mid - 1;
                break;
            }

            // If the left half is sorted, the pivot must be in the right half
            if (nums[mid] >= nums[0]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        // If no pivot is found, the array might not be rotated, set pivot to last element
        if (pivot == -1) {
            pivot = n - 1;
        }

        // Determine which half of the array to search
        if (target >= nums[0] && target <= nums[pivot]) {
            s = 0;
            e = pivot;  // Search in the left half
        } else {
            s = pivot + 1;
            e = n - 1;  // Search in the right half
        }

        // Binary search for the target
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        // If target is not found
        return -1;
    }
};
