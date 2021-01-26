package main

import (
	"fmt"
)

func intToArray(k int) (ans []int) {
	if k == 0 {
		return []int{0}
	}
	for k > 0 {
		ans = append([]int{k % 10}, ans...)
		k = k / 10
	}
	return
}

func intToArrayR(k int) (ans []int) {
	if k == 0 {
		return []int{0}
	}
	for k > 0 {
		//ans = append([]int{k%10}, ans...)
		ans = append(ans, k%10)
		k = k / 10
	}
	//sort.Reverse(sort.IntSlice(ans))
	ans = reverse(ans)
	return
}

func addTwoArrays(a, b []int) []int {
	n := len(a)
	var ans []int
	var carry int
	for i := n - 1; i >= 0; i-- {
		tmp := a[i] + b[i] + carry
		ans = append([]int{tmp % 10}, ans...)
		carry = tmp / 10
	}
	if carry > 0 {
		ans = append([]int{carry}, ans...)
	}
	return ans
}

func addTwoArraysR(a, b []int) []int {
	n := len(a)
	var ans []int
	var carry int
	for i := n - 1; i >= 0; i-- {
		tmp := a[i] + b[i] + carry
		ans = append(ans, tmp%10)
		carry = tmp / 10
	}
	if carry > 0 {
		ans = append(ans, carry)
	}
	//sort.Reverse(sort.IntSlice(ans))
	ans = reverse(ans)
	return ans
}

func reverse(arr []int) []int {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
	return arr
}

func addToArrayForm(A []int, K int) []int {
	k := intToArrayR(K)
	na, nk := len(A), len(k)
	if na > nk {
		k = append(make([]int, na-nk), k...)
	} else if na < nk {
		A = append(make([]int, nk-na), A...)
	}
	return addTwoArraysR(A, k)
}

func main() {
	answer := addToArrayForm([]int{1, 2, 0, 0}, 34)
	fmt.Printf("answer: %v\n", answer)
}
