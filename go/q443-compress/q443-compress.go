package q443_compress

func compress(chars []byte) int {
	index := 0 // 一段相同字符的头部
	curCh := chars[0]

	var fillInd int

	i := 1
	for i < len(chars) {
		if curCh == chars[i] {
			i++
		} else {
			length := i - index
			if length > 1 {
				chars[fillInd] = chars[index]
				fillInd++
				sli := int2ByteSlice(length)
				for _, v := range sli {
					chars[fillInd] = v
					fillInd++
				}
			} else {
				chars[fillInd] = chars[index]
				fillInd++
			}
			index = i
			curCh = chars[index]
			i++
		}
	}

	length := i - index
	if length > 1 {
		chars[fillInd] = chars[index]
		fillInd++
		sli := int2ByteSlice(length)
		for _, v := range sli {
			chars[fillInd] = v
			fillInd++
		}
	} else {
		chars[fillInd] = chars[index]
		fillInd++
	}

	return fillInd
}

func int2ByteSlice(d int) []byte {
	var sli []byte

	for d > 0 {
		sli = append(sli, byte(d%10+'0'))
		d = d / 10
	}

	l, r := 0, len(sli)-1
	for l < r {
		sli[l], sli[r] = sli[r], sli[l]
		l++
		r--
	}

	return sli
}
