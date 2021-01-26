package main

import (
	"fmt"
	"sort"
)

func numEquivDominoPairs(dominoes [][]int) int {
	mp := make(map[[2]int]int)
	for i := range dominoes {
		sort.Ints(dominoes[i])
		var tmp [2]int
		copy(tmp[:], dominoes[i])
		mp[tmp]++
	}
	ans := 0
	for _, v := range mp {
		ans += v * (v - 1) / 2
	}
	return ans
}

func main() {
	ans := numEquivDominoPairs([][]int{
		{1, 2},
		{2, 1},
		{3, 4},
		{5, 6},
	})
	fmt.Printf("answer: %v\n", ans)
}
