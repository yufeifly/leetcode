package main

type Point struct {
	X, Y int
}

type NeighborSum struct {
	Matrices [][]int
	Location map[int]Point
}

func Constructor(grid [][]int) NeighborSum {
	var nei NeighborSum
	nei.Location = make(map[int]Point)

	nei.Matrices = grid

	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			nei.Matrices[i][j] = grid[i][j]
			nei.Location[grid[i][j]] = Point{
				X: i,
				Y: j,
			}
		}
	}

	return nei
}

func (this *NeighborSum) AdjacentSum(value int) int {
	valLocation := this.Location[value]
	x, y := valLocation.X, valLocation.Y

	var result int
	if x-1 >= 0 {
		result += this.Matrices[x-1][y]
	}
	if y-1 >= 0 {
		result += this.Matrices[x][y-1]
	}
	if x+1 < len(this.Matrices) {
		result += this.Matrices[x+1][y]
	}
	if y+1 < len(this.Matrices[0]) {
		result += this.Matrices[x][y+1]
	}

	return result
}

func (this *NeighborSum) DiagonalSum(value int) int {
	valLocation := this.Location[value]
	x, y := valLocation.X, valLocation.Y

	var result int
	if x-1 >= 0 && y-1 >= 0 {
		result += this.Matrices[x-1][y-1]
	}
	if y+1 < len(this.Matrices[0]) && x-1 >= 0 {
		result += this.Matrices[x-1][y+1]
	}
	if x+1 < len(this.Matrices) && y+1 < len(this.Matrices) {
		result += this.Matrices[x+1][y+1]
	}
	if y-1 >= 0 && x+1 < len(this.Matrices) {
		result += this.Matrices[x+1][y-1]
	}

	return result
}

/**
 * Your NeighborSum object will be instantiated and called as such:
 * obj := Constructor(grid);
 * param_1 := obj.AdjacentSum(value);
 * param_2 := obj.DiagonalSum(value);
 */
