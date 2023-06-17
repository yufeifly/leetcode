package main

import (
	"container/heap"
	"fmt"
)

type number struct {
	index, num int
}

type hp []number

func (h hp) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *hp) Push(x interface{}) {
	*h = append(*h, x.(number))
}

func (h *hp) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]

	return x
}
func (h hp) Top() interface{} {
	//n := len(h)
	return h[0]
}

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].num > h[j].num }

func maxSlidingWindowHeap(nums []int, k int) []int {
	n := len(nums)
	var ans []int
	h := &hp{}
	for i := 0; i < k; i++ {
		heap.Push(h, number{i, nums[i]})
	}
	ans = append(ans, h.Top().(number).num)
	for i := k; i < n; i++ {
		heap.Push(h, number{i, nums[i]})
		for h.Top().(number).index <= i-k {
			heap.Pop(h)
		}
		ans = append(ans, h.Top().(number).num)
	}
	return ans
}

func main() {
	ans := maxSlidingWindowHeap([]int{1, 3, -1, -3, 5, 3, 6, 7}, 3)
	fmt.Println(ans)
}
