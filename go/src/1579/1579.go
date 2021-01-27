package main

import "fmt"

func maxNumEdgesToRemove(n int, edges [][]int) int {
	var ansSli []int
	alice, bob := NewUnionFind(n+1), NewUnionFind(n+1)
	// type 3
	for i, v := range edges {
		if v[0] == 3 {
			parentu, parentv := alice.find(v[1]), alice.find(v[2])
			if parentu != parentv {
				alice.union(v[2], v[1])
				bob.union(v[2], v[1])
				ansSli = append(ansSli, i)
			}
		}
	}
	// type 1, 2
	for i, v := range edges {
		if v[0] == 1 {
			parentu, parentv := alice.find(v[1]), alice.find(v[2])
			if parentu != parentv {
				alice.union(v[2], v[1])
				ansSli = append(ansSli, i)
			}
		} else if v[0] == 2 {
			parentu, parentv := bob.find(v[1]), bob.find(v[2])
			if parentu != parentv {
				bob.union(v[2], v[1])
				ansSli = append(ansSli, i)
			}
		}
	}
	//fmt.Printf("anssclice: %v\n", ansSli)
	if alice.size[alice.find(edges[0][1])] != n || bob.size[bob.find(edges[0][1])] != n {
		//fmt.Printf("alice: %v\n", alice.size[alice.find(edges[0][1])])
		//fmt.Printf("bob: %v\n", bob.size[bob.find(edges[0][1])])
		return -1
	}
	return len(edges) - len(ansSli)
}

type unionFind struct {
	parent []int
	size   []int
}

func NewUnionFind(n int) *unionFind {
	p := make([]int, n)
	sz := make([]int, n)
	for i := range p {
		p[i] = i
		sz[i] = 1
	}
	return &unionFind{parent: p, size: sz}
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
		u.size[parenty] += u.size[parentx]
	}
}

func main() {
	answer := maxNumEdgesToRemove(4, [][]int{
		{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4},
	})
	fmt.Printf("answer: %v\n", answer)
}
