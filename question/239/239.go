package main

func maxSlidingWindow(nums []int, k int) []int {
	n := len(nums)
	var ans []int
	index, curMax := 0, nums[0]
	left, right := 0, 0
	for right < k {
		if nums[right] >= curMax {
			index = right
			curMax = nums[right]
		}
		right++
	}
	right--
	ans = append(ans, curMax)
	for right < n {
		if right+1 >= n {
			break
		}
		t1 := nums[right+1]
		if index == left {
			index, curMax = getMax(nums, left+1, right+1)
		} else {
			if t1 >= curMax {
				index = right + 1
				curMax = nums[right+1]
			}
		}
		ans = append(ans, curMax)
		left++
		right++
	}
	return ans
}

func getMax(nums []int, left, right int) (int, int) {
	index, curMax := left, nums[left]
	for i := left + 1; i <= right; i++ {
		if nums[i] >= curMax {
			index = i
			curMax = nums[i]
		}
	}
	return index, curMax
}

//func main() {
//	answer := maxSlidingWindow([]int{1,3,-1,-3,5,3,6,7}, 3)
//	fmt.Println(answer)
//}
