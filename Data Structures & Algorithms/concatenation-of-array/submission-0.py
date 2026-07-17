class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ans: List[int] = []

        for i in range(0,2):
            for i in nums:
                ans.append(i)

        return ans;