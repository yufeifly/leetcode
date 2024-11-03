package main

import (
	"fmt"
	"math/bits"
	"strconv"
	"strings"
)

func main() {
	result := minChanges3(13, 4)
	fmt.Println(result)
}

func minChanges3(n int, k int) int {
	if n&k == k { // 说明n可以通过1改0操作等于k
		return bits.OnesCount(uint(n ^ k))
	}

	return -1
}

func minChanges2(n int, k int) int {
	result := 0

	for n > 0 || k > 0 {
		nRemainder := n % 2
		kRemainder := k % 2

		if nRemainder == 0 && kRemainder == 1 {
			return -1
		} else if nRemainder == 1 && kRemainder == 0 {
			result++
		}

		n = n / 2
		k = k / 2
	}

	return result
}

func minChanges(n int, k int) int {
	nBinary := GetBinary(n)
	kBinary := GetBinary(k)

	nBinary, kBinary = Align(nBinary, kBinary)

	result := 0

	for i := 0; i < len(nBinary); i++ {
		if nBinary[i] == kBinary[i] {
			continue
		} else if nBinary[i] == '0' && kBinary[i] == '1' {

			return -1
		} else if nBinary[i] == '1' && kBinary[i] == '0' {
			result++
		}
	}

	return result
}

func GetBinary(num int) string {
	d := num

	var result string

	for d > 0 {
		remainder := d % 2
		result = strconv.FormatInt(int64(remainder), 10) + result
		d = d / 2
	}

	return result
}

func Align(n, k string) (string, string) {
	if len(n) > len(k) {
		k = strings.Repeat("0", len(n)-len(k)) + k
	} else if len(n) < len(k) {
		n = strings.Repeat("0", len(k)-len(n)) + n
	}
	return n, k
}
