class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        ans = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] <= ans[i - 1]:
                ans.append(ans[i - 1] + 1)
            else:
                ans.append(nums[i]);
        c = 0
        for i in range(len(nums)):
            c += abs(nums[i] - ans[i])
        return c