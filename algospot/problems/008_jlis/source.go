package main

import "fmt"

var n,m int

var arr_1[101] int
var arr_2[101] int

var cache[102][102] int


func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve(pos_1, pos_2 int) int {

	if (pos_1 == n-1) && (pos_2 == m-1) {
		return 0
	}

	if cache[pos_1+1][pos_2+1] != -1 {
		return cache[pos_1+1][pos_2+1]
	}
	var value, value_1, value_2 int
		
	if pos_1 == -1 {
		value_1 = -(1<<32)
	} else {
		value_1 = arr_1[pos_1]
	}

	if pos_2 == -1 {
		value_2 = -(1<<32)
	} else {
		value_2 = arr_2[pos_2]
	}

	value = max(value_1, value_2)
	var ret = 0
	for i := pos_1 + 1; i < n; i++ {
		if arr_1[i] > value {
			ret = max(ret, 1 + solve(i, pos_2))
		}
	}

	for i := pos_2 + 1; i < m; i++ {
		if arr_2[i] > value {
			ret = max(ret, 1 + solve(pos_1, i))
		}
	}

	cache[pos_1+1][pos_2+1] = ret
	return ret



	

}

func main() {
	var C int
	fmt.Scanf("%d", &C)

	for TC := 0; TC < C; TC ++ {
		fmt.Scanf("%d %d", &n, &m)

		for i := 0; i < n; i++ {
			fmt.Scanf("%d", &arr_1[i])
		}

		for i := 0; i < m; i++ {
			fmt.Scanf("%d", &arr_2[i])
		}

		arr_1[n] = (1<<32)
		arr_2[m] = (1<<32)

		for i := 0; i < n+1; i++ {
			for j := 0; j < m+1; j++ {
				cache[i][j] = -1
			}
		}

		fmt.Println(solve(-1, -1))


	}
}
