package main

import (
	"fmt"
)

func partition(s string) [][]string {
	var ret [][]string
	ret = helper(s, 0)
	//fmt.Println(ret)
	return ret
}

func helper(s string, start int) [][]string {
	//	fmt.Println(start)
	if start == len(s) {
		var ret [][]string
		return ret
	}
	var answer [][]string
	for i := start; i < len(s); i++ {
		if isPalindrom(s[start : i+1]) {
			left := s[start : i+1]
			//			fmt.Println("left: ", left)
			r := helper(s, i+1)
			//			fmt.Println("r: ", r, "index: ", start)
			if len(r) == 0 {
				v := []string{left}
				answer = append(answer, v)
			}
			for _, v := range r {
				//				fmt.Println("before", v)
				v = append([]string{left}, v...)
				//				fmt.Println("after", v)
				answer = append(answer, v)
			}
		}
	}
	return answer
}

func isPalindrom(s string) bool {
	i := 0
	j := len(s) - 1
	for i < j {
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}

func main() {
	str := "aab"
	answer := partition(str)
	fmt.Println(answer)
}
