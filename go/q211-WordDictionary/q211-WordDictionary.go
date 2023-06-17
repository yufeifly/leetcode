package q211_WordDictionary

type WordDictionary struct {
	children [26]*WordDictionary
	isEnd    bool
}

func Constructor() WordDictionary {
	return WordDictionary{}
}

func (w *WordDictionary) AddWord(word string) {
	node := w
	for _, v := range word {
		if node.children[v-'a'] == nil {
			node.children[v-'a'] = &WordDictionary{}
		}
		node = node.children[v-'a']
	}
	node.isEnd = true
}

func (w *WordDictionary) Search(word string) bool {
	node := w
	nodes := []*WordDictionary{node}
	var candidates []*WordDictionary

	for _, ch := range word {
		if ch != '.' {
			candidates = nil
			for _, n := range nodes {
				if n.children[ch-'a'] != nil {
					candidates = append(candidates, n.children[ch-'a'])
				}
			}
			if len(candidates) <= 0 {
				return false
			}
			nodes = candidates
		} else {
			candidates = nil
			for _, n := range nodes {
				for _, child := range n.children {
					if child != nil {
						candidates = append(candidates, child)
					}
				}
			}
			nodes = candidates
		}
	}

	for _, n := range nodes {
		if n.isEnd {
			return true
		}
	}

	return false
}

// todo 搜索的时候使用dfs
