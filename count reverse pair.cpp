#include <iostream>
#include <vector>

using namespace std;

// Merge function to count reverse pairs during the merge step
int mergeAndCount(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
    int count = 0;
    int i = left, j = mid + 1, k = left;

    // Count the reverse pairs
    while (i <= mid && j <= right) {
        if (nums[i] > 2LL * nums[j]) {
            count += (mid - i + 1);
            j++;
        } else {
            i++;
        }
    }

    // Merge the sorted halves
    i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    // Copy remaining elements
    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    // Copy the merged array back to the original array
    for (int l = left; l <= right; l++) {
        nums[l] = temp[l];
    }

    return count;
}

// Merge sort function to recursively divide and conquer
int mergeSortAndCount(vector<int>& nums, vector<int>& temp, int left, int right) {
    int count = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively count reverse pairs in left and right halves
        count += mergeSortAndCount(nums, temp, left, mid);
        count += mergeSortAndCount(nums, temp, mid + 1, right);

        // Merge the two halves and count reverse pairs during the merge
        count += mergeAndCount(nums, temp, left, mid, right);
    }

    return count;
}

// Main function to count reverse pairs
int countReversePairs(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp(n);

    // Call the merge sort function
    return mergeSortAndCount(nums, temp, 0, n - 1);
}

int main() {
    // Example usage
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << "Number of reverse pairs: " << countReversePairs(nums) << endl;
    return 0;
}
