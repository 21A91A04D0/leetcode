class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high) {
        int temp[high + 1];
        int i = low;
        int j = mid + 1;
        int n = high;
        int k = low;
        while(i <= mid && j <= n) {
            if(nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            }
            else {
                temp[k++] = nums[j++];
            }
        }
        while(i <= mid) {
            temp[k++] = nums[i++];
        }
        while(j <= n) {
            temp[k++] = nums[j++];
        }
        for(int i = low; i <= n ; i++) {
            nums[i] = temp[i];
        }
    }
    void mergeSort(vector<int> &nums, int low, int high) {
        if(low >= high) return;
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};