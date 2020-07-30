class Solution {
private:
    int search(vector<int> & nums, int l, int r) {
        if(l == r) return nums[l];
        int mid = l + (r - l)/2;
        
        if(nums[mid] > nums[r]) return search(nums, mid + 1, r);
        if(nums[mid] < nums[r]) return search(nums, l, mid);
        return search(nums, l, r - 1);
    }
    
public:
    /*
    int findMin_naive(vector<int>& nums) {
        int size = nums.size();
        
        for(int i = 1; i < size; i++){
            if(nums[i] < nums[i - 1]) {
                return nums[i];
            }
        }
        return nums[0];
    }
    */
    /*int findMin_Recursive(vector<int>& nums) {
        int r = nums.size() - 1;
        return(search(nums, 0, r));
    }*/
    
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + (r - l)/2;

            if(nums[mid] > nums[r]) l = mid + 1; //return search(nums, mid + 1, r);
            else if(nums[mid] < nums[r]) r = mid; //return search(nums, l, mid);
            else r -= 1;
        }
        return nums[l];
    }
};
