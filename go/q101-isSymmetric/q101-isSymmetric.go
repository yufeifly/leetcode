package q101_isSymmetric

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 递归
func isSymmetric(root *TreeNode) bool {
	return check(root, root)
}

func check(left *TreeNode, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	}

	if left != nil && right != nil {
		if left.Val == right.Val {
			return check(left.Left, right.Right) && check(left.Right, right.Left)
		}
	}

	return false
}

// todo 迭代
