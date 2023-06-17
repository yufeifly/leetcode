package q388_lengthLongestPath

import "strings"

type Node struct {
	name  string
	level int
}

func lengthLongestPath(input string) int {
	var st []string

	rootDir := getRootDir(input)
	if rootDir != "" {
		st = append(st, rootDir)
	}

	cur := len(rootDir)
	var curNode Node

	ans := 0

	for getNextPart(input, &cur, &curNode) {
		if isFile(curNode.name) {
			// 计算当前长度
			if curNode.level > len(st)-1 {
				st = append(st, curNode.name)
			} else {
				st[curNode.level] = curNode.name
				st = st[:curNode.level+1]
			}

			cusL := getLength(st)
			if cusL > ans {
				ans = cusL
			}
		} else {
			if curNode.level > len(st)-1 {
				st = append(st, curNode.name)
			} else {
				st[curNode.level] = curNode.name
				st = st[:curNode.level+1]
			}
		}
	}

	return ans
}

func getLength(st []string) int {
	var length int
	for _, v := range st {
		length += len(v)
	}

	return length + len(st) - 1
}

func getNextPart(input string, index *int, node *Node) bool {
	level := 0

	if *index >= len(input) {
		return false
	}

	for i := *index; i < len(input); i++ {
		if i == *index && input[i] == '\n' {
			continue
		} else if input[i] == '\t' {
			level++
		} else if input[i] == '\n' {
			node.name = trim(input[*index:i])
			node.level = level
			*index = i
			return true
		}
	}

	node.name = trim(input[(*index):])
	node.level = level
	*index = len(input)

	return true
}

func trim(s string) string {
	return strings.Trim(strings.Trim(s, "\n"), "\t")
}

func getRootDir(input string) string {
	for i, ch := range input {
		if ch == '\n' {
			if isFile(input[:i]) {
				return ""
			}
			return input[:i]
		}
	}

	return ""
}

func isFile(f string) bool {
	return strings.Contains(f, ".")
}
