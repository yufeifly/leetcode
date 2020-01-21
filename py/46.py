class Solution:
    n = 0
    output = []
    def permute(self, nums):
        self.output.clear()
        self.n = len(nums)
        self.backtrace(0,nums)
        return self.output
        
    def backtrace(self,lev,nums):
        if lev == self.n:
            self.output.append(nums[:])
        for i in range(lev,self.n):
            nums[lev],nums[i] = nums[i],nums[lev]
            self.backtrace(lev+1,nums)
            nums[lev],nums[i] = nums[i],nums[lev]

sol = Solution()
answer = sol.permute([1,2,3])
for s in answer:
    print(s)
answer = sol.permute([1])
for s in answer:
    print(s)
