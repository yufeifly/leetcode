package main

import (
	"fmt"
)

func numSimilarGroups(strs []string) int {
	n := len(strs)
	uf := newUnionFind(n)
	for i, v := range strs {
		for j := i + 1; j < n; j++ {
			if uf.find(i) == uf.find(j) {
				continue
			}
			if isSimilar(v, strs[j]) {
				uf.union(j, i)
			}
		}
	}
	var ans int
	for i := range strs {
		if uf.find(i) == i {
			ans++
		}
	}
	return ans
}

func isSimilar(a, b string) bool {
	cnt := 0
	for i := range a {
		if a[i] == b[i] {
			cnt++
		}
	}
	diff := len(a) - cnt
	if diff == 0 || diff == 2 {
		return true
	}
	return false
}

type unionFind struct {
	parent []int
}

func newUnionFind(n int) *unionFind {
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
	//answer := numSimilarGroups([]string{"tars","rats","arts","star"})
	answer := numSimilarGroups([]string{"omv", "ovm"})
	fmt.Println(answer)
}
