package main

import (
	"fmt"
//	"github.com/golang-collections/collections/queue"
)

func canFinish(numCourses int, prerequisites [][]int) bool {
	indegrees := make([]int,numCourses)
	for _, cp := range prerequisites {
		indegrees[cp[0]]++
	}
	que := New()
	for i:=0; i<numCourses; i++ {
		if indegrees[i]== 0 {
			que.Enqueue(i)
		}
	}
	for que.Len() > 0 {
		pre := que.Peek().(int)
		que.Dequeue()
		numCourses--
		for _, req := range prerequisites {
			if req[1] != pre {
				continue
			} else {
				indegrees[req[0]]--
				if indegrees[req[0]] == 0 {
					que.Enqueue(req[0])
				}
			}
			
		}
	}
	return numCourses == 0
}


func main() {
	pre := [][]int{
		{1,0},
		{0,1},
	}
	fmt.Println(canFinish(2,pre))
}

type (
	Queue struct {
		start, end *node
		length int
	}
	node struct {
		value interface{}
		next *node
	}
)

// Create a new queue
func New() *Queue {
	return &Queue{nil,nil,0}
}
// Take the next item off the front of the queue
func (this *Queue) Dequeue() interface{} {
	if this.length == 0 {
		return nil
	}
	n := this.start
	if this.length == 1 {
		this.start = nil
		this.end = nil
	} else {
		this.start = this.start.next
	}
	this.length--
	return n.value
}
// Put an item on the end of a queue
func (this *Queue) Enqueue(value interface{}) {
	n := &node{value,nil}
	if this.length == 0 {
		this.start = n
		this.end = n
	} else {
		this.end.next = n
		this.end = n
	}
	this.length++
}
// Return the number of items in the queue
func (this *Queue) Len() int {
	return this.length
}
// Return the first item in the queue without removing it
func (this *Queue) Peek() interface{} {
	if this.length == 0 {
		return nil
	}
	return this.start.value
}
