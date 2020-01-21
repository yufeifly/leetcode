class Solution:
    def permuteUnique(self, nums):
        answer = []
        sz = len(nums)
        if sz == 0:
            return answer
        used = [False] * sz
        nums.sort()
        tmp = []
        def dfs(lev):
            if lev == sz:
                answer.append(tmp.copy())
                return
            for i in range(sz):
                if not used[i]:
                    if i > 0 and nums[i] == nums[i-1] and not used[i-1]:
                        continue
                    tmp.append(nums[i])
                    used[i] = True
                    dfs(lev+1)
                    used[i] = False
                    tmp.pop()
        dfs(0)
        return answer

sol = Solution()
answer = sol.permuteUnique([1,2,1])
for i in answer:
    print(i)
