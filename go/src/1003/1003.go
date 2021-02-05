package main

import "fmt"

func isValid(s string) bool {
	st := make([]rune, 0)
	for _, ch := range s {
		if ch == 'c' {
			n := len(st)
			if n < 2 {
				return false
			}
			if !(st[n-1] == 'b' && st[n-2] == 'a') {
				return false
			}
			st = st[:n-2]
		} else {
			st = append(st, ch)
		}
	}
	return len(st) == 0
}

func main() {
	ans := isValid("aabcbc")
	fmt.Println(ans)
}
