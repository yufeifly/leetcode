package q122_maxprofit

// 这种动态规划使用二维数组，占用空间太大
func maxProfit(prices []int) int {
	n := len(prices)
	
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
	}

	for dist := 1; dist < n; dist++ {
		for i :=0;i+dist < n; i++ {
			j := i + dist
			if dist == 1 {
				dp[i][j] = max(0, prices[j] - prices[i])
			} else {
				dp[i][j] = max(0, prices[j] - prices[i])
				for k := i;k<j;k++ {
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j])
				}
			}	
		}
	}

	return dp[0][n-1]
}

func max(a, b int) int {
	if a> b {
		return a
	}

	return b
}


// 占用空间更小的动态规划策略
// dp[i] 表示第i天交易结束后的最大收益
// dp[i][0] 表示第i天交易结束后持有股票的最大收益
// dp[i][1] 表示第i天交易结束后未持有股票的最大收益
func maxProfit_2(prices []int) int {
	n := len(prices)

	dp := make([][2]int, n + 1)
	
	dp[0][0] = -prices[0]

	for i:=1;i<n; i++ {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i])
		dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i])
	}

	return dp[n-1][1]
}

// 还有一种方法就是找到所有的“上坡”
func maxProfit_3(prices []int) int {
	n := len(prices)

	left, right := 0, 1

	answer := 0

	for right < n {
		if prices[right] >= prices[right-1] {
			right++
		} else {
			answer += prices[right-1] - prices[left]
			left, right = right, right+1
		}
	}
	if right > left {
		answer += prices[right-1] - prices[left]
	}

	return answer
}