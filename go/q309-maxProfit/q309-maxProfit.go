package q309_maxPorfit

// 动态规划
func maxProfit(prices []int) int {
	// dp[i] 表示第i天交易结束后的最大收益
	// dp[i][0] 手上持有股票的最大收益
	// dp[i][1] 手上不持有股票，且处于冷冻期的最大收益
	// dp[i][2] 手上不持有股票，且不处于冷冻期的最大收益
	dp := make([][3]int, len(prices))

	dp[0][0] = -prices[0]

	for i:=1;i < len(prices);i++ {
		dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i])// 要么是前一天就持有股票，要么今天刚买的
		dp[i][1] = dp[i-1][0] + prices[i]
		dp[i][2] = max(dp[i-1][1], dp[i-1][2])
	}

	return max(dp[len(prices)-1][1], dp[len(prices)-1][2]) 
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}