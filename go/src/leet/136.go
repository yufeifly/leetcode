package main

import (
	"fmt"
)

func singleNumber(nums []int) int {
	answer := nums[0]
	for i := 1; i < len(nums); i++ {
		answer = answer ^ nums[i]
	}
	return answer
}

func main() {
	nums := []int{4, 1, 2, 1, 2}
	fmt.Println(singleNumber(nums))
}
