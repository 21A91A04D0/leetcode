class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n
        a = n - k;
        b = nums[a:] + nums[0:a];
        nums[:] = b[:]
        