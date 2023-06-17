package q567_checkInclusion

func checkInclusion(s1 string, s2 string) bool {
	if len(s1) > len(s2) {
		return false
	}

	s1Dict := getDict(s1)
	tail := len(s1) - 1
	s2Dict := getDict(s2[:tail+1])

	for tail < len(s2) {
		if mapEqual(s1Dict, s2Dict) {
			return true
		}
		s2Dict[s2[tail+1-len(s1)]]--
		if s2Dict[s2[tail+1-len(s1)]] == 0 {
			delete(s2Dict, s2[tail+1-len(s1)])
		}
		if tail+1 < len(s2) {
			s2Dict[s2[tail+1]]++
		}
		tail++
	}

	return false
}

func mapEqual(s, t map[byte]int) bool {
	for k, v := range s {
		if v != t[k] {
			return false
		}
	}

	return true
}

func getDict(s string) map[byte]int {

	dict := make(map[byte]int)
	for _, v := range s {
		dict[byte(v)]++
	}

	return dict
}
