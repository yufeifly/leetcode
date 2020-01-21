package main

import (
	"fmt"
)

func main() {
	b := make([][]int, 5, 10)
	b[0] = []int{1, 2, 3}
	b[1] = []int{4, 5, 6}
	fmt.Println(b)
}
