package main

import "fmt"



func solve(s string) (string, int) {
	if s[0] != 'x' {
		return s[0:1], 1
	} else {
		var ret1,ret2,ret3,ret4 string
		var size = 0
		var ret_size = 1
		
		ret1, size = solve(s[ret_size:])
		ret_size += size

		ret2, size = solve(s[ret_size:])
		ret_size += size

		ret3, size = solve(s[ret_size:])
		ret_size += size

		ret4, size = solve(s[ret_size:])
		ret_size += size

		return "x" + ret3 + ret4 + ret1 + ret2, ret_size

	}
}

func main() {
	var input string
	var output string
	var C int
	fmt.Scan(&C)

	for TC := 0; TC < C; TC++ {
		fmt.Scan(&input)
		output,_ = solve(input)
		fmt.Println(output)

	}
}
