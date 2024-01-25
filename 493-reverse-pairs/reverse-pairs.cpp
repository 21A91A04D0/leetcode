class Solution {
public:
    int cnt = 0;
    void merge(vector<int> &arr, int low, int mid, int high) {
        int l = low;
        int r = mid + 1;
        while(l <= mid) {
            while(r <= high && arr[l] > (1LL * 2 * arr[r])) {
                r++;

            }
            cnt += r - (mid + 1);
            l++;
        }
        int i = low;
        int j = mid + 1;
        int temp[high + 1];
        int k = low;
        while(i <= mid && j <= high){
            if(arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
            }
        }
        while(i <= mid) {
            temp[k++] = arr[i++];
        }
        while(j <= high) {
            temp[k++] = arr[j++];
        }
        for(int i = low ; i <= high ; i++) {
            arr[i] = temp[i];
        }
    }
    void mergeSort(vector<int> &nums, int low, int high) {
        if(low >= high) return;
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return cnt;
    }
};