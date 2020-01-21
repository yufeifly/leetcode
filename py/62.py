from queue import Queue
# import os
""" class Solution:
    #超时了
    def uniquePaths(self, m, n):
        answer = 0
        next = [[1,0],[0,1]]
        que = Queue()
        que.put([0,0])
        while not que.empty():
            tmp = que.get()
            #print(tmp[1] == n)
            if tmp[0] == m-1 and tmp[1] == n-1:
                answer += 1
            else :
                for s in next:
                    x = s[0] + tmp[0] 
                    y = s[1] + tmp[1]
                    if not(x < 0 or x >= m or y < 0 or y >=n):
                        que.put([x,y])
        return answer """

class Solution:
    #超时了
    def uniquePaths(self, m, n):
        dp = [[1]*(n)]*(m)
        #print(dp)
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[m-1][n-1]
sol = Solution2()
print(sol.uniquePaths(7,3))
            


