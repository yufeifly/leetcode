package main

import "fmt"

func hitBricks(grid [][]int, hits [][]int) []int {

	rows, cols := len(grid), len(grid[0])
	copy := make([][]int, rows)

	parent := make([]int, rows*cols+1)
	size := make([]int, rows*cols+1)

	for i, _ := range parent {
		parent[i] = i
		size[i] = 1
	}

	for i, val := range grid {
		//copy[i] = append([]int(nil), val...)
		copy[i] = append(copy[i], val...)
	}
	// 得到最终状态
	for _, val := range hits {
		copy[val[0]][val[1]] = 0
	}
	// functions
	var find func(int) int
	find = func(x int) int {
		if parent[x] != x {
			parent[x] = find(parent[x])
		}
		return parent[x]
	}

	union := func(from, to int) {
		from, to = find(from), find(to)
		if from != to {
			size[to] += size[from]
			parent[from] = to
		}
	}

	getIndex := func(x, y int) int {
		return x*cols + y
	}
	//
	for i, row := range copy {
		for j, _ := range row {
			fmt.Printf("i:%v,j:%v,parent:%v\n", i, j, parent[getIndex(i, j)])
		}
	}
	fmt.Println("===")
	// 建立并查集
	root := rows * cols
	for i, row := range copy {
		for j, v := range row {
			if v == 0 {
				continue
			}
			if i == 0 {
				union(getIndex(i, j), root)
			}
			if i > 0 && copy[i-1][j] == 1 {
				union(getIndex(i, j), getIndex(i-1, j))
			}
			if i == 3 && j == 2 && parent[getIndex(i, j)] == 5 {
				for i, row := range copy {
					for j, _ := range row {
						fmt.Printf("i:%v,j:%v,parent:%v\n", i, j, parent[getIndex(i, j)])
					}
				}
				fmt.Println("---")
			}
			if j > 0 && copy[i][j-1] == 1 {
				union(getIndex(i, j), getIndex(i, j-1))
			}
			if i == 3 && j == 2 && parent[getIndex(i, j)] == 5 {
				for i, row := range copy {
					for j, _ := range row {
						fmt.Printf("i:%v,j:%v,parent:%v\n", i, j, parent[getIndex(i, j)])
					}
				}
				fmt.Println("+++")
			}
		}
	}
	//
	for i, row := range copy {
		for j, _ := range row {
			fmt.Printf("i:%v,j:%v,parent:%v\n", i, j, parent[getIndex(i, j)])
		}
	}
	fmt.Printf("root size : %v\n", size[root])
	//
	type pair struct{ x, y int }
	directions := []pair{{-1, 0}, {1, 0}, {0, -1}, {0, 1}} // 上下左右
	ans := make([]int, len(hits))

	for i := len(hits) - 1; i >= 0; i-- {
		r, c := hits[i][0], hits[i][1]
		if grid[r][c] == 0 {
			continue
		}
		previousSize := size[find(root)]
		if r == 0 {
			union(c, root)
		}
		for _, d := range directions {
			if newR, newC := r+d.x, c+d.y; 0 <= newR && newR < rows && 0 <= newC && newC < cols && copy[newR][newC] == 1 {
				union(getIndex(r, c), getIndex(newR, newC))
			}
		}
		curSize := size[find(root)]
		if curSize-previousSize-1 > 0 {
			ans[i] = curSize - previousSize - 1
		} else {
			ans[i] = 0
		}
		copy[r][c] = 1
	}

	return ans
}

func main() {
	grid := [][]int{{1, 0, 0}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}}
	hits := [][]int{{2, 1}}
	ans := hitBricks(grid, hits)
	for _, val := range ans {
		fmt.Printf("%v\n", val)
	}
}
