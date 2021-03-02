package main

import (
	"fmt"
	"sort"
)

var rows, cols int

type edge struct {
	u, v, diff int
}

func getIndex(x, y int) int {
	return x*cols + y
}

func abs(x, y int) int {
	if x > y {
		return x - y
	}
	return y - x
}

func minimumEffortPath(heights [][]int) int {
	rows, cols = len(heights), len(heights[0])
	edges := make([]edge, (rows-1)*cols+(cols-1)*rows)
	ind := 0
	for i, row := range heights {
		for j := range row {
			if j+1 < cols {
				edges[ind] = edge{getIndex(i, j), getIndex(i, j+1), abs(heights[i][j], heights[i][j+1])}
				ind++
			}
			if i+1 < rows {
				edges[ind] = edge{getIndex(i, j), getIndex(i+1, j), abs(heights[i][j], heights[i+1][j])}
				ind++
			}
		}
	}
	sort.Slice(edges, func(i, j int) bool {
		return edges[i].diff < edges[j].diff
	})
	uf := NewUnionFind(rows * cols)
	for _, e := range edges {
		uf.union(e.v, e.u)
		if uf.find(0) == uf.find(rows*cols-1) {
			return e.diff
		}
	}
	return 0
}

type unionFind struct {
	parent []int
}

func NewUnionFind(n int) *unionFind {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	return &unionFind{
		parent: p,
	}
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
	answer := minimumEffortPath([][]int{
		//{1, 2, 1, 1, 1},
		//{1, 2, 1, 2, 1},
		//{1, 2, 1, 2, 1},
		//{1, 2, 1, 2, 1},
		//{1, 1, 1, 2, 1},
		{1, 2, 2},
		{3, 8, 2},
		{5, 3, 5},
	})
	fmt.Println(answer)
	//sort.Search()
}
