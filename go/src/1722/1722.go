package main

import (
	"fmt"
)

func minimumHammingDistance(source []int, target []int, allowedSwaps [][]int) int {
	n := len(source)
	uf := NewUnionFind(n)
	for _, v := range allowedSwaps {
		uf.union(v[0], v[1])
	}
	mp := make(map[int][]int)
	for i := 0; i < n; i++ {
		mp[uf.find(i)] = append(mp[uf.find(i)], i)
	}
	var dis int
	for _, v := range mp {
		var src, tar []int
		for _, seq := range v {
			src = append(src, source[seq])
			tar = append(tar, target[seq])
		}
		dis += getDistance(src, tar)
		//fmt.Printf("dis: %v\n",dis)
	}
	return dis
}

// 寻找两个数组的交集
func getDistance(source []int, target []int) int {
	//sort.Ints(source)
	//sort.Ints(target)
	//fmt.Printf("source: %v\n", source)
	//fmt.Printf("target: %v\n", target)
	n := len(source)
	var intersection int

	for i := range source {
		for j := range target {
			if source[i] == target[j] {
				intersection++
				target = append(target[:j], target[j+1:]...)
				break
			}
		}
	}
	return n - intersection
}

func main() {
	ans := minimumHammingDistance([]int{1, 2, 3, 4}, []int{2, 1, 4, 5}, [][]int{
		{0, 1},
		{2, 3},
	})

	fmt.Printf("answer: %v\n", ans)
}

type unionFind struct {
	parent []int
}

func NewUnionFind(n int) *unionFind {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	return &unionFind{parent: p}
}

func (u *unionFind) find(x int) int {
	if x != u.parent[x] {
		u.parent[x] = u.find(u.parent[x])
	}
	return u.parent[x]
}

func (u *unionFind) union(x, y int) {
	parentx, parenty := u.find(x), u.find(y)
	if parentx != parenty {
		u.parent[parentx] = parenty
	}
}
