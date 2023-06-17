package q474_findMaxForm

import "strings"

// 01背包问题，限制多了1维，为2维
// a[i][j][k]表示前i个字符串最多j个0和最多k个1的最大长度
// a[i+1][j][k] = max(a[i+1][j][k], a[i][j-zeros][k-ones] + 1)
func findMaxForm(strs []string, m int, n int) int {
	a := make([][][]int, len(strs)+1)
	for i := range a {
		a[i] = make([][]int, m+1)
		for j := range a[i] {
			a[i][j] = make([]int, n+1)
		}
	}

	for i := range strs {
		zeros := strings.Count(strs[i], "0")
		ones := len(strs[i]) - zeros

		for j := 0; j<=m;j++ {
			for k := 0;k<=n;k++ {
				a[i+1][j][k] = a[i][j][k]
				if j >= zeros && k >= ones {
					a[i+1][j][k] = max(a[i+1][j][k], a[i][j-zeros][k-ones] + 1)
				}
			}
		}
	}

	return a[len(strs)][m][n]
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}