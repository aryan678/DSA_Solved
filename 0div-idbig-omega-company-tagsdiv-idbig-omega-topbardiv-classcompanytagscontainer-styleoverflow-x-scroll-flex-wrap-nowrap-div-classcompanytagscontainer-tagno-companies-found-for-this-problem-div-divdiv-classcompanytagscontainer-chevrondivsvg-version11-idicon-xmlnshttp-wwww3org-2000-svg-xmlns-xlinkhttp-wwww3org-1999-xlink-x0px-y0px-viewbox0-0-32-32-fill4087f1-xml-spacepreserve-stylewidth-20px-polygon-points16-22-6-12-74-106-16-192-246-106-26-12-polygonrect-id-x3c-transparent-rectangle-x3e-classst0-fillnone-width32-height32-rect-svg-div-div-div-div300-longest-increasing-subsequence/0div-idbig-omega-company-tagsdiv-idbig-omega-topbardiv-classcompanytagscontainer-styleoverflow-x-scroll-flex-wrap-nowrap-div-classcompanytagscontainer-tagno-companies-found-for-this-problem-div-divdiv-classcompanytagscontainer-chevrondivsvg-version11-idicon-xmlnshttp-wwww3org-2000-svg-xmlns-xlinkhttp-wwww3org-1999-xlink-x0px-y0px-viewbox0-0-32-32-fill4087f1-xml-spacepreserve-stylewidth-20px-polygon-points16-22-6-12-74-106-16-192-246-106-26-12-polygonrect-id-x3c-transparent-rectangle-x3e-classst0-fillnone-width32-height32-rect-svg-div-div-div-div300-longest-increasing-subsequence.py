class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        li = [1] * len(nums)
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    li[i] = max(li[i], li[j] + 1)

        return max(li)