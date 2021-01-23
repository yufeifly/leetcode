package main

import "fmt"

var (
	rows, cols int
)

func hitBricks(grid [][]int, hits [][]int) []int {

	rows, cols := len(grid), len(grid[0])
	copy := make([][]int, rows)

	for i, val := range grid {
		//copy[i] = append([]int(nil), val...)
		copy[i] = append(copy[i], val...)
	}
	// 得到最终状态
	for _, val := range hits {
		copy[val[0]][val[1]] = 0
	}

	// functions
	getIndex := func(x, y int) int {
		return x*cols + y
	}
	//
	root := rows * cols
	uf := NewUnionFind(root + 1)

	// 建立并查集
	for i, row := range copy {
		for j, v := range row {
			if v == 0 {
				continue
			}
			if i == 0 {
				uf.union(getIndex(i, j), root)
			}
			if j > 0 && copy[i][j-1] == 1 {
				uf.union(getIndex(i, j), getIndex(i, j-1))
			}

			if i > 0 && copy[i-1][j] == 1 {
				uf.union(getIndex(i, j), getIndex(i-1, j))
			}
		}
	}
	//
	type pair struct{ x, y int }
	directions := []pair{{-1, 0}, {1, 0}, {0, -1}, {0, 1}} // 上下左右
	ans := make([]int, len(hits))

	for i := len(hits) - 1; i >= 0; i-- {
		r, c := hits[i][0], hits[i][1]
		if grid[r][c] == 0 {
			continue
		}
		previousSize := uf.size[uf.find(root)]
		if r == 0 {
			uf.union(c, root)
		}
		for _, d := range directions {
			if newR, newC := r+d.x, c+d.y; 0 <= newR && newR < rows && 0 <= newC && newC < cols && copy[newR][newC] == 1 {
				uf.union(getIndex(r, c), getIndex(newR, newC))
			}
		}
		curSize := uf.size[uf.find(root)]
		if curSize-previousSize-1 > 0 {
			ans[i] = curSize - previousSize - 1
		} else {
			ans[i] = 0
		}
		copy[r][c] = 1
	}

	return ans
}

type unionFind struct {
	parent []int
	size   []int
}

func NewUnionFind(n int) *unionFind {
	p := make([]int, n)
	s := make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = i
		s[i] = 1
	}
	return &unionFind{
		parent: p,
		size:   s,
	}
}

func (u *unionFind) find(x int) int {
	if x != u.parent[x] {
		u.parent[x] = u.find(u.parent[x])
	}
	return u.parent[x]
}

func (u *unionFind) union(x, y int) {
	parentx := u.find(x)
	parenty := u.find(y)
	if parentx == parenty {
		return
	}
	u.parent[parentx] = parenty
	u.size[parenty] += u.size[parentx]
}

func (u *unionFind) getSize(x int) int {
	parentx := u.find(x)
	return u.size[parentx]
}

func main() {
	grid := [][]int{{1, 0, 0}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}}
	hits := [][]int{{2, 1}}
	ans := hitBricks(grid, hits)
	for _, val := range ans {
		fmt.Printf("%v\n", val)
	}
}
