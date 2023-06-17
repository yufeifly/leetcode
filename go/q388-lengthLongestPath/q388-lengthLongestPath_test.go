package q388_lengthLongestPath

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func Test_lengthLongestPath(t *testing.T) {
	Convey("Test_getRootDir", t, func() {
		So(getRootDir("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"), ShouldEqual, `dir`)
	})

	Convey("Test_getNextPart", t, func() {

		Convey("t1", func() {
			var node Node
			var cur int
			getNextPart("file.ext", &cur, &node)
			So(node.name, ShouldEqual, "file.ext")
			So(node.level, ShouldEqual, 0)
		})

		Convey("t2", func() {
			var node Node
			var cur int
			getNextPart("file1.txt\nfile2.txt\nlongfile.txt", &cur, &node)
			So(node.name, ShouldEqual, "file1.txt")
			So(cur, ShouldEqual, 9)
			getNextPart("file1.txt\nfile2.txt\nlongfile.txt", &cur, &node)
			So(node.name, ShouldEqual, "file2.txt")
			getNextPart("file1.txt\nfile2.txt\nlongfile.txt", &cur, &node)
			So(node.name, ShouldEqual, "longfile.txt")
		})
	})

	Convey("Test_lengthLongestPath", t, func() {
		So(lengthLongestPath("file.ext"), ShouldEqual, 8)
		So(lengthLongestPath("a"), ShouldEqual, 0)
		So(lengthLongestPath("file1.txt\nfile2.txt\nlongfile.txt"), ShouldEqual, 12)
		So(lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"), ShouldEqual, 32)
		So(lengthLongestPath("dir\n        file.txt"), ShouldEqual, 16)
	})

	Convey("Test_getLength", t, func() {
		So(getLength([]string{"dir", "subdir2", "subsubdir2", "file2.ext"}), ShouldEqual, 32)
	})
}
