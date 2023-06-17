package main

import (
	"bytes"
	"fmt"
	"sort"
)

func smallestStringWithSwaps(s string, pairs [][]int) string {
	n := len(s)
	for i := range pairs {
		if pairs[i][0] > pairs[i][1] {
			pairs[i][0], pairs[i][1] = pairs[i][1], pairs[i][0]
		}
	}
	uf := NewUnionFind(n)
	for i := range pairs {
		uf.union(pairs[i][1], pairs[i][0])
	}
	mp := make(map[int][]int)
	for i, ch := range s {
		mp[uf.find(i)] = append(mp[uf.find(i)], int(ch))
	}
	for i := range mp {
		sort.Ints(mp[i])
	}
	var b bytes.Buffer
	for i := 0; i < n; i++ {
		p := uf.find(i)
		b.WriteRune(rune(mp[p][0]))
		mp[p] = mp[p][1:]

	}
	return b.String()
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
	s := smallestStringWithSwaps("dcab", [][]int{
		{0, 3},
		{1, 2},
	})
	fmt.Printf("answer: %v\n", s)
}
