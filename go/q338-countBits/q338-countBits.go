package q338_countBits

func countBits(n int) []int {
	ans := []int{0, 1, 1}

	if n == 0 {
		return ans[:1]
	}
	if n == 1 {
		return ans[:2]
	}
	if n == 2 {
		return ans
	}

	for i := 3; i <= n; i++ {
		if i&1 == 1 {
			ans = append(ans, ans[i/2]+1)
		} else {
			ans = append(ans, ans[i/2])
		}
	}

	return ans
}
