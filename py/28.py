class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        answer = -1
        len_haystack,len_needle = len(haystack),len(needle)
        for i in range(len_haystack - len_needle + 1) :
            if haystack[i:i+len_needle] == needle:
                answer = i
                break
        return answer

haystack = "hello"
needle = "ll"
sol = Solution()
print(sol.strStr(haystack,needle))

