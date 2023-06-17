package q423_originalDigits

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func Test_originalDigits(t *testing.T) {

	Convey("Test_originalDigits", t, func() {
		So(originalDigits("owoztneoer"), ShouldEqual, "012")
	})

}
