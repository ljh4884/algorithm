package main

import "fmt"
var n,m int

var friend[10][10] int
var check[10] int
func solve(pos int) int {
	if pos == n {
		return 1
	}

	var ret = 0
	var i = 0
	for ; i < n; i++ {
		if check[i] == 0 {
			break
		}
	}
	check[i] = 1
	for j := 0; j < n; j++ {
		if check[j] == 1 {
			continue
		}
		if friend[i][j] == 1 {
			check[j] = 1
			ret += solve(pos+2)
			check[j] = 0
		}
	}
	check[i] = 0

	return ret
	
	
}

func main() {
	var C int
	fmt.Scan(&C)
	for TC := 0; TC < C; TC++ {
		fmt.Scan(&n, &m)

		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				friend[i][j] = 0
			}
			check[i] = 0
		}

		var fri1, fri2 int
		
		for i := 0; i < m; i++ {
			fmt.Scan(&fri1, &fri2)
			friend[fri1][fri2] = 1
			friend[fri2][fri1] = 1
		}

		fmt.Println(solve(0))
		

	}
}
