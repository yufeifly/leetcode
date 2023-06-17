package main

import (
	"fmt"
)

func makeConnected(n int, connections [][]int) int {
	if len(connections)+1 < n {
		return -1
	}
	for i, val := range connections {
		if val[0] > val[1] {
			connections[i][0], connections[i][1] = val[1], val[0]
		}
	}
	uf := NewUnionFind(n)
	for _, val := range connections {
		uf.union(val[1], val[0])
	}
	var ans int
	for i := 0; i < n; i++ {
		if i == uf.find(i) {
			ans++
		}
	}
	return ans - 1
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

func main() {
	p := makeConnected(4, [][]int{
		{0, 1},
		{0, 2},
		{1, 2},
	})
	fmt.Printf("ans: %v\n", p)
}
