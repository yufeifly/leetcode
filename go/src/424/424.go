package main

func characterReplacement(s string, k int) int {
	num := make([]int, 26)
	n := len(s)
	left, right := 0, 0
	maxWin := 0
	for right < n {
		num[s[right]-'A']++
		maxWin = max(maxWin, num[s[right]-'A'])
		if right-left+1 > k+maxWin {
			num[s[left]-'A']--
			left++
		}
		right++
	}
	return right - left
}
