package q443_compress

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func Test_compress(t *testing.T) {

	Convey("Test_compress", t, func() {
		Convey("e1", func() {
			arr := []byte{'a', 'a', 'b', 'b', 'c', 'c', 'c'}
			So(compress(arr), ShouldEqual, 6)
			So(arr[:6], ShouldResemble, []byte{'a', '2', 'b', '2', 'c', '3'})
		})

		Convey("e2", func() {
			arr := []byte{'a'}
			So(compress(arr), ShouldEqual, 1)
			So(arr[:1], ShouldResemble, []byte{'a'})
		})

		Convey("e3", func() {
			arr := []byte{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}
			So(compress(arr), ShouldEqual, 4)
			So(arr[:4], ShouldResemble, []byte{'a', 'b', '1', '2'})
		})
	})

	Convey("Test_int2ByteSlice", t, func() {
		Convey("should pass", func() {
			So(int2ByteSlice(3), ShouldResemble, []byte{'3'})
			So(int2ByteSlice(12), ShouldResemble, []byte{'1', '2'})
		})
	})
}
