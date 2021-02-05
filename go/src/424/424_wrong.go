package main

import "fmt"

func characterReplacementWrong(s string, k int) int {
	n := len(s)
	var ans int
	left, right := 0, 0
	for left < n {
		right = left
		leftover := k
		for right < n && (s[right] == s[left] || leftover > 0) {
			if s[right] != s[left] {
				leftover--
			}
			right++
		}
		ans = max(ans, right-left)
		ch := s[left]
		for left < n && s[left] == ch {
			left++
		}
	}
	//
	left, right = n-1, n-1
	for right >= 0 {
		left = right
		leftover := k
		for left >= 0 && (s[left] == s[right] || leftover > 0) {
			if s[left] != s[right] {
				leftover--
			}
			left--
		}
		ans = max(ans, right-left)
		ch := s[right]
		for right >= 0 && s[right] == ch {
			right--
		}
	}

	return ans
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func main() {
	ans := characterReplacement("ABBB", 2)
	fmt.Println(ans)
}
