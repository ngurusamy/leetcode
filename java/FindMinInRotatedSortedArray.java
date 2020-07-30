class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        while(l < r) {
            int mid = l + (r - l)/2;

            if(nums[mid] > nums[r]) l = mid + 1; //return search(nums, mid + 1, r);
            else if(nums[mid] < nums[r]) r = mid; //return search(nums, l, mid);
            else r -= 1;
        }
        return nums[l];
    }
}
