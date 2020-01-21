class Solution:
    def merge(self, nums1, m, nums2, n) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i,j = m-1, n-1
        cnt = m+n-1
        while j >= 0 and i >=0:
            if nums2[j] < nums1[i]:
                nums1[cnt] = nums1[i]; cnt -= 1
                i -= 1
                #print(nums1)
            else :
                nums1[cnt] = nums2[j]; cnt -= 1
                j -= 1
                #print(nums1)
        if i < 0 and j >= 0:
            while j >= 0:
                nums1[cnt] = nums2[j];
                j -= 1
                cnt -= 1
        for elem in nums1:
            print(elem)

sol = Solution()
sol.merge([2,5,6,0,0,0],3,[1,2,3],3)
