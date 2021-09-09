package main

import "fmt"
import "sort"
var n,k int

func main() {
	var C = 0
	fmt.Scan(&C)
	
	for TC := 0; TC < C; TC++ {
		fmt.Scan(&n,&k)

		var list = []int{}
		for i := 0; i < n; i++ {
			list = append(list, (i+1))
		}
		var pos = 0
		for ;len(list) != 2; {
			list = append(list[:pos], list[pos+1:]...)
			pos = (pos + k - 1) % len(list)
		}
		sort.Ints(list)
		fmt.Println(list[0], list[1])
	}
}
