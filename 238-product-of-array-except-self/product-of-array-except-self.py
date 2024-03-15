class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        pro = 1
        dic = {0:0}
        for i in nums:
            if i == 0:
                dic[0] += 1
            else:
                pro = pro * i
        print(pro)
        for j in range(len(nums)):
            if dic[0] == 0:
                nums[j] = pro // nums[j]
            elif dic[0] == 1:
                if nums[j] == 0:
                    nums[j] = pro
                else:
                    nums[j] = 0
            else:
                nums[j] = 0
        return nums