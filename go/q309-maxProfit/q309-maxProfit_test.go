package q309_maxPorfit

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func Test_maxProfit(t *testing.T) {
	Convey("maxTest_maxProfit", t , func() {
		So(maxProfit([]int{1,2,3,0,2}), ShouldEqual, 3)
	})
}
