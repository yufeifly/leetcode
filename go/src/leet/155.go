package main

import (
	"fmt"
)

type MinStack struct {
	st *Stack
	log *Stack
}


/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{st : New(),log : New()} 
}

func (this *MinStack) Push(x int)  {
	this.st.Push(x)
	if this.log.Len() <= 0 {
		this.log.Push(x)
	} else if x < this.log.Peek().(int) {
		this.log.Push(x)
	} else {
		this.log.Push(this.log.Peek().(int))
	}
}


func (this *MinStack) Pop()  {
	this.st.Pop()
	this.log.Pop()
}


func (this *MinStack) Top() int {
	return this.st.Peek().(int)
}


func (this *MinStack) GetMin() int {
	return this.log.Peek().(int)
}

func main () {
	obj := Constructor()	
	obj.Push(1)
	obj.Push(2)
	obj.Push(5)
	obj.Push(3)
	obj.Pop()
	p1 := obj.Top()
	fmt.Println(p1)
	p2 := obj.GetMin()
	fmt.Println(p2)
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */

 type (
	Stack struct {
		top *node
		length int
	}
	node struct {
		value interface{}
		prev *node
	}
)
// Create a new stack
func New() *Stack {
	return &Stack{nil,0}
}
// Return the number of items in the stack
func (this *Stack) Len() int {
	return this.length
}
// View the top item on the stack
func (this *Stack) Peek() interface{} {
	if this.length == 0 {
		return nil
	}
	return this.top.value
}
// Pop the top item of the stack and return it
func (this *Stack) Pop() interface{} {
	if this.length == 0 {
		return nil
	}

	n := this.top
	this.top = n.prev
	this.length--
	return n.value
}
// Push a value onto the top of the stack
func (this *Stack) Push(value interface{}) {
	n := &node{value,this.top}
	this.top = n
	this.length++
}
