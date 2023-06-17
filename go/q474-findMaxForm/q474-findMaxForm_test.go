package q474_findMaxForm

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func Test_findMaxForm(t *testing.T) {
	Convey("Test_findMaxForm", t, func() {
		So(findMaxForm([]string{"10", "0001", "111001", "1", "0"}, 5, 3), ShouldEqual, 4)
	})
}
