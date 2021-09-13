package main

import "fmt"

var div = 10000000
var n int

var cache[101][101] int


func solve(rest, prev int) int {
	
	if rest == 0 {
		return 1
	}

	if cache[rest][prev] != -1 {
		return cache[rest][prev]
	}

	var ret = 0
	for i := 1; i <= rest; i++ {
		if prev == 0 {
			ret += solve(rest-i, i)
		} else {
			ret += ((prev + i - 1) * solve(rest-i, i))
		}
		ret %= 10000000
	}

	cache[rest][prev] = ret
	return ret

}

func main() {
	var C = 0
	fmt.Scan(&C)
	for i := 0; i < 101; i++ {
		for j := 0; j < 101; j++ {
			cache[i][j] = -1
		}
	}
	for TC := 0; TC < C; TC++ {
		fmt.Scan(&n)
		fmt.Println(solve(n,0))
	}
}
