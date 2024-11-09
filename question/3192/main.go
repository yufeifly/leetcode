package main

/*
是二进制数组全部等于1的最少操作次数

1. 下表i到数组末尾应看为一个整体，将这个整体和i-1位去思考
2. 设整体（i到末尾）变为1的操作次数为x，则新整体（i-1到末尾）变为1的操作次数与i-1位的值有关；
3. i-1位为1，则新整体变为1的操作次数也为x；i-1位为0，则新整体变为1的操作次数为原整体变为0的操作次数+1；
*/

type DP struct {
	To1 int
	To0 int
}

func minOperations(nums []int) int {
	dpArr := make([]DP, len(nums))

	for i := len(nums) - 1; i >= 0; i-- {
		j := len(nums) - 1 - i
		if nums[i] == 1 { // 当前值等于1
			if i == len(nums)-1 {
				dpArr[j] = DP{To1: 0, To0: 1}
			} else {
				dpArr[j] = DP{To1: dpArr[j-1].To1, To0: dpArr[j-1].To1 + 1}
			}
		} else { // 当前值等于0
			if i == len(nums)-1 {
				dpArr[j] = DP{To1: 1, To0: 0}
			} else {
				dpArr[j] = DP{To1: dpArr[j-1].To0 + 1, To0: dpArr[j-1].To0}
			}
		}
	}

	return dpArr[len(nums)-1].To1
}

func main() {
	result := minOperations([]int{0, 1, 1, 0, 1})
	println(result)
}
