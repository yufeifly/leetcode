package q189_rotate

func rotate(nums []int, k int) {
	k = k % len(nums)

	reverse(nums)
	reverse(nums[0:k])
	reverse(nums[k:])
}

func reverse(arr []int) {
	left, right := 0, len(arr)-1

	for left < right {
		arr[left], arr[right] = arr[right], arr[left]
		left++
		right--
	}
}
