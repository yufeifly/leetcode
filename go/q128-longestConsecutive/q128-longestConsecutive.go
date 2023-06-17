package q128_longestConsecutive

func longestConsecutive(nums []int) int {
	numSet := map[int]bool{}
	for _, v := range nums {
		numSet[v] = true
	}

	longest := 0

	for k, _ := range numSet {
		if !numSet[k-1] {
			curLen := 1
			for numSet[k+1] {
				curLen++
				k++
			}
			if longest < curLen {
				longest = curLen
			}
		}
	}

	return longest
}
