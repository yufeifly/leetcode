package main

func longestWPIWrong(hours []int) int {
	n := len(hours)
	ans := 0
	curTiredDays, curEasyDays := 0, 0
	left, right := 0, 0
	flag := false
	for right < n {
		if left > right {
			right++
			continue
		}
		if hours[right] > 8 {
			if !flag {
				curTiredDays++
			}

			if curTiredDays > curEasyDays {
				ans = max(ans, curTiredDays+curEasyDays)
				right++
				flag = false
			} else {
				if (n - right - 1) <= curEasyDays-curTiredDays {
					//fmt.Printf("left1: %v, right1: %v\n", left, right)
					tired := hours[left] > 8
					if tired && right > left {
						curTiredDays--
					} else if !tired && right > left {
						curEasyDays--
					}
					left++
					flag = true
				} else {
					right++
					flag = false
				}
			}
		} else {
			if !flag {
				curEasyDays++
			}
			if curTiredDays > curEasyDays {
				ans = max(ans, curTiredDays+curEasyDays)
				right++
				flag = false
			} else {
				if (n - right) <= curEasyDays-curTiredDays {
					//fmt.Printf("left1: %v, right1: %v\n", left, right)
					tired := hours[left] > 8
					if tired && right > left {
						curTiredDays--
					} else if !tired && right > left {
						curEasyDays--
					}
					left++
					flag = true
				} else {
					right++
					flag = false
				}
			}
		}
		//fmt.Printf("left: %v, right: %v, t: %v, e: %v\n", left, right, curTiredDays, curEasyDays)
		//fmt.Printf("ans: %v\n", ans)
	}
	return ans
}

//func longestWPI(hours []int) int {
//
//}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

//func main() {
//	ans := longestWPI([]int{6,6,9})
//	fmt.Println(ans)
//}
