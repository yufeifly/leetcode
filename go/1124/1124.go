package main

import "fmt"

func longestWPI(hours []int) int {
	n := len(hours)
	score := make([]int, n)
	for i, v := range hours {
		if v > 8 {
			score[i] = 1
		} else {
			score[i] = -1
		}
	}
	presum := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		presum[i] = presum[i-1] + score[i-1]
	}
	//var stack []int
	//for i := range presum {
	//	if stack == nil || presum[i] < presum[stack[len(stack)-1]] {
	//		stack = append(stack, i)
	//	}
	//}
	//ans := 0
	//i := n
	//for i > ans {
	//	for len(stack) > 0 && presum[i] > presum[stack[len(stack)-1]] {
	//		ans = max2(ans, i - (stack[len(stack)-1]))
	//		stack = stack[:len(stack)-1]
	//	}
	//	i--
	//}
	for d := n; d > 0; d-- {
		for i := 0; i+d <= n; i++ {
			if presum[i+d] > presum[i] {
				return d
			}
		}
	}
	return 0
}

func max2(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func main() {
	//ans := longestWPI([]int{6,6,9})
	ans := longestWPI([]int{9, 9, 6, 0, 6, 6, 9})
	fmt.Println(ans)
}
