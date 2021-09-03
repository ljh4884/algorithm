package main

import "fmt"

var div = 10000000
var n int

var cache[101]


func solve(rest, prev int) int {
	if prev == 0 {
		
	}

	if rest == 1 {
		return prev
	}
	var ret = 0
	for i := 1; i <= rest; i++ {
		ret += (prev + i - 1) 
	}

}

func main() {
	var C = 0
	fmt.Scan(&C)
	cache[0] = 0
	cache[1] = 1
	for TC := 0; TC < C; TC++ {
		fmt.Scan(n)
	}
}
