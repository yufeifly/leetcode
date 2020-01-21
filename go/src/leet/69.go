package main

import (
	"fmt"
	"math"
)

func getbit(x int) int {
	answer := 0
	for x > 0 {
		x = x / 10
		answer += 1
	}
	return answer
}

func mySqrt(x int) int {
	var answer int
	bit := getbit(x)
	left := int(math.Pow(10, float64((bit+1)/2-1)))
	right := int(math.Pow(10, float64((bit+1)/2)))
	for left <= right {
		mid := (left + right) / 2
		less := mid * mid
		more := (mid + 1) * (mid + 1)
		if less <= x && more > x {
			answer = mid
			break
		} else if less < x {
			left = mid + 1
		} else {
			right = mid - 1
		}
		//		fmt.Println(mid)
	}
	return answer
}

func main() {
	fmt.Println(mySqrt(100000))
}
