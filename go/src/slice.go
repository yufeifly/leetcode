package main

import (
	"fmt"
)

func main() {
	var a [][]string
	a = append(a, []string{"1ab", "2fdsf", "3"})
	a = append(a, []string{"2", "2", "5"})
	a = append(a, []string{"6", "7", "8"})
	fmt.Println(a)
}
