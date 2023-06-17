package q41_firstMissingPositive

func firstMissingPositive(nums []int) int {
	numMap := make(map[int]bool)

	minPositive := int(^uint(0) >> 1)

	for _, v := range nums {
		if v > 0 {
			numMap[v] = true
			if v < minPositive {
				minPositive = v
			}
		}
	}

	if minPositive == 1 {
		candidate := 2
		for numMap[candidate] {
			candidate++
		}

		return candidate
	}

	return 1
}
