package q98_isValidBST

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

const (
	INT_MAX = int64(^uint64(0) >> 1)
	INT_MIN = ^INT_MAX
)

func isValidBST(root *TreeNode) bool {
	return check(root, INT_MIN, INT_MAX)
}

func check(root *TreeNode, low, high int64) bool {
	if root == nil {
		return true
	}

	if int64(root.Val) > low && int64(root.Val) < high {
		return check(root.Left, low, int64(root.Val)) &&
			check(root.Right, int64(root.Val), high)
	}

	return false
}
