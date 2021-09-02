package main

import "fmt"

var n,m int

var arr_1[100] int
var arr_2[100] int

var cache[101][101][201] int


func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve(pos_1, pos_2, prev_pos int) int {
	if (pos_1 == n) && (pos_2 == m) {
		return 0
	}
	
	
	if cache[pos_1][pos_2][prev_pos+1] != -1 {
		return cache[pos_1][pos_2][prev_pos+1]
	}
	
	var prev_value = 0
	if prev_pos == -1 {
		prev_value = -(1<<32)
	} else if prev_pos < 100 {
		prev_value = arr_1[prev_pos]
	} else {
		prev_value = arr_2[prev_pos-100]
	}
	
	var ret = 0


	if pos_1 < n {
		if arr_1[pos_1] > prev_value {
			ret = 1 + solve(pos_1 + 1, pos_2, pos_1)
		}
		ret = max(ret, solve(pos_1 + 1, pos_2, prev_pos))
	}

	if pos_2 < m {
		if arr_2[pos_2] > prev_value {
			ret = max(ret, 1 + solve(pos_1, pos_2 + 1, pos_2 + 100))
		}
		ret = max(ret, solve(pos_1, pos_2 + 1, prev_pos))
	}
	cache[pos_1][pos_2][prev_pos+1] = ret
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

		for i := 0; i <= n; i++ {
			for j := 0; j <= m; j++ {
				for k := 0; k < 101 + m; k++ {
					cache[i][j][k] = -1
				}
			}
		}

		fmt.Println(solve(0, 0, -1))


	}
}
