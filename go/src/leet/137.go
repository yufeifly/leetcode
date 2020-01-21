package main

import (
	"fmt"
)

//func singleNumber(nums []int) int {
//	sort.Ints(nums)
//	pin := nums[0]
//	for i := 2; i < len(nums); i += 3 {
//		if nums[i] != pin {
//			return pin
//		} else {
//			pin = nums[i+1]
//		}
//	}
//	//fmt.Println(nums)
//	return pin
//}

func singleNumber(nums []int) {

}

func main() {
	vec := []int{0, 1, 0, 1, 0, 1, 99}
	fmt.Println(singleNumber(vec))
}
