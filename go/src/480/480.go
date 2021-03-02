package main

import (
	"container/heap"
	"fmt"
	"sort"
)

var delayed map[int]int
var small, large *hp

type hp struct {
	sort.IntSlice
	sz int
}

func (h *hp) Pop() interface{} {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}

func (h *hp) Push(v interface{}) {
	h.IntSlice = append(h.IntSlice, v.(int))
}

func (h *hp) push(v int) {
	h.sz++
	heap.Push(h, v)
}

func (h *hp) pop() int {
	h.sz--
	return heap.Pop(h).(int)
}

func (h *hp) prune() {
	for h.Len() > 0 {
		num := h.IntSlice[0]
		if h == small {
			num = -num
		}
		if d, ok := delayed[num]; ok {
			if d > 1 {
				delayed[num]--
			} else {
				delete(delayed, num)
			}
			heap.Pop(h)
		} else {
			break
		}
	}
}

func medianSlidingWindow(nums []int, k int) []float64 {
	n := len(nums)
	delayed = make(map[int]int)
	var answer []float64
	small, large = &hp{}, &hp{}
	balance := func() {
		if small.sz-large.sz > 1 {
			large.push(-small.pop())
			small.prune()
		} else if small.sz < large.sz {
			small.push(-large.pop())
			large.prune()
		}
	}
	insert := func(num int) {
		if small.sz == 0 || num <= -small.IntSlice[0] {
			small.push(-num)
		} else {
			large.push(num)
		}
		balance()
	}
	erase := func(num int) {
		delayed[num]++
		if num <= -small.IntSlice[0] {
			small.sz--
			if num == -small.IntSlice[0] {
				small.prune()
			}
		} else {
			large.sz--
			if num == large.IntSlice[0] {
				large.prune()
			}
		}
		balance()
	}
	getMedian := func() float64 {
		if k&1 > 0 {
			return float64(-small.IntSlice[0])
		}
		return float64(-small.IntSlice[0]+large.IntSlice[0]) / 2
	}
	for _, v := range nums[:k] {
		insert(v)
	}
	answer = append(answer, getMedian())
	for i := k; i < n; i++ {
		insert(nums[i])
		erase(nums[i-k])
		answer = append(answer, getMedian())
	}
	return answer
}

func main() {
	ans := medianSlidingWindow([]int{1, 4, 2, 3}, 4)
	fmt.Println(ans)
}
