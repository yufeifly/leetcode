package main

import (
	"container/list"
	"fmt"
)

func main() {
	temperatures := []int{73, 74, 75, 71, 69, 72, 76, 73}
	answer := dailyTemperatures(temperatures)
	for _, val := range answer {
		fmt.Println(val)
	}
}

//func dailyTemperatures(T []int) []int {
//	for i:=0;i<len(T)-1;i++ {
//		temp := T[i]
//		T[i] = 0
//		for j:=i+1;j<len(T);j++ {
//			if T[j] > temp {
//				T[i] = j - i
//				break
//			}
//		}
//	}
//	T[len(T)-1] = 0
//	return T
//}

func dailyTemperatures(T []int) []int {
	if len(T) <= 1 {
		T[0] = 0
		return T
	}
	l := list.New()
	l.PushBack(0)
	for i := 1; i < len(T); i++ {
		for l.Len() > 0 && T[i] > T[l.Back().Value.(int)] {
			tmp := l.Remove(l.Back())
			T[tmp.(int)] = i - tmp.(int)
		}
		l.PushBack(i)
	}

	for l.Len() > 0 {
		tmp := l.Remove(l.Back())
		T[tmp.(int)] = 0
	}
	return T
}
