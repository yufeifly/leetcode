package main

import (
	"fmt"
)

func search(nums []int, target int) bool {
	left := 0
	right := len(nums) - 1
	var mid int
	for left <= right {
		mid = (left + right) / 2
		if nums[mid] == target {
			return true
		}
		if nums[left] == nums[mid] {
			left++
			continue
		}
		if nums[left] < nums[mid] {
			if target >= nums[left] && target < nums[mid] {
				right = mid - 1
			} else {
				left = mid + 1
			}
		} else {
			//后半部分有序
			if target <= nums[right] && target > nums[mid] {
				left = mid + 1
			} else {
				right = mid - 1
			}
		}
	}
	return false
}

func main() {
	nums := []int{12, 3, 43, 656, 4}
	fmt.Println(search(nums, 0))
}
