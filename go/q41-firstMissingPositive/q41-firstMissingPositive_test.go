package q41_firstMissingPositive

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func Test_firstMissingPositive(t *testing.T) {

	Convey("Test_firstMissingPositive", t, func() {
		So(firstMissingPositive([]int{1, 2, 0}), ShouldEqual, 3)
		So(firstMissingPositive([]int{3, 4, -1, 1}), ShouldEqual, 2)
		So(firstMissingPositive([]int{7, 8, 9, 11, 12}), ShouldEqual, 1)
	})

}
