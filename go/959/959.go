package main

import "fmt"

func regionsBySlashes(grid []string) int {
	n := len(grid) * 2
	uf := NewUnionFind(n * n)
	m := make([][]bool, n)
	for i := range m {
		m[i] = make([]bool, n)
	}
	fmt.Printf("m: %v\n", m)
	for i, s := range grid {
		for j, c := range s {
			if c == '/' {
				m[2*i][2*j+1] = true
				m[2*i+1][2*j] = true
				uf.parent[getIndex(2*i, 2*j+1, n)] = -1
				uf.parent[getIndex(2*i+1, 2*j, n)] = -1
			} else if c == '\\' {
				m[2*i][2*j] = true
				m[2*i+1][2*j+1] = true
				uf.parent[getIndex(2*i, 2*j, n)] = -1
				uf.parent[getIndex(2*i+1, 2*j+1, n)] = -1
			}
		}
	}
	fmt.Printf("m: %v\n", m)
	for i, v := range m {
		for j := range v {
			if m[i][j] == true {
				continue
			}
			if j > 0 && m[i][j-1] == false {
				uf.union(getIndex(i, j, n), getIndex(i, j-1, n))
			}
			if i > 0 && m[i-1][j] == false {
				uf.union(getIndex(i, j, n), getIndex(i-1, j, n))
			}
		}
	}
	answerMap := make(map[int]bool)
	for i := range m {
		for j := range m[i] {
			if m[i][j] == true {
				continue
			}
			parent := uf.find(getIndex(i, j, n))
			if parent == -1 {
				continue
			}
			answerMap[parent] = true
		}
	}
	return len(answerMap)
}

func getIndex(x, y, n int) int {
	return x*n + y
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
	answer := regionsBySlashes([]string{
		"//",
		"/ ",
	})
	fmt.Printf("answer: %v\n", answer)
}
