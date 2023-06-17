package q423_originalDigits

import "strconv"

func originalDigits(s string) string {
	numbers := []string{"zero", "two", "six", "eight", "four", "three", "five", "one", "seven", "nine"}
	numberMap := map[string]int{
		"zero":  0,
		"two":   2,
		"six":   6,
		"eight": 8,
		"four":  4,
		"three": 3,
		"five":  5,
		"one":   1,
		"seven": 7,
		"nine":  9,
	}

	charMap := make(map[rune]int)

	for _, ch := range s {
		charMap[ch]++
	}

	var arr [10]int

	for _, number := range numbers {
		bingo := true
		times := 5000
		for _, ch := range number {
			if !(charMap[ch] > 0) {
				bingo = false
				break
			}
			if charMap[ch] < times {
				times = charMap[ch]
			}
		}
		if bingo {
			arr[numberMap[number]] += times
			for _, ch := range number {
				charMap[ch] -= times
			}
		}
	}

	var answer string
	for k, v := range arr {
		if v > 0 {
			answer += getDuplicateStr(k, v)
		}
	}

	return answer
}

func getDuplicateStr(k, v int) string {
	var s string
	for i := 0; i < v; i++ {
		s += strconv.FormatInt(int64(k), 10)
	}

	return s
}
