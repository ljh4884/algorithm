package main

import "fmt"

var n,d,p,t int
var A[50][50] int

var cache[50][100] float64
var count[50] float64

func solve(pos, day int) float64 {
	if day == d {
		if pos == p {
			return 1.0
		} 
		return 0.0
	}

	if cache[pos][day] > -0.5 {
		return cache[pos][day]
	}

	var ret = 0.0
	for i := 0; i < n; i++ {
		if A[pos][i] == 1 {
			ret += (solve(i, day+1) / count[i])
		}
	}
	cache[pos][day] = ret
	return ret
}

func main() {
	var C = 0
	fmt. Scan(&C)
	for TC := 0; TC < C; TC++ {
		fmt.Scan(&n,&d,&p)
		
		for i := 0; i < n; i++ {
			count[i] = 0
			for j := 0; j < n; j++ {
				fmt.Scan(&A[i][j])
				if A[i][j] == 1 {
					count[i] += 1.0
				}
			}
		}

		fmt.Scan(&t)

		for i := 0; i < t; i++ {
			for j := 0; j < n; j++ {
				for k := 0; k < d; k++ {
					cache[j][k] = -1.0
				}
			}
			var cur int
			fmt.Scan(&cur)
			fmt.Print(solve(cur,0))
			fmt.Print(" ")
		}
		fmt.Println()
	}
}
