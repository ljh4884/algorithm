package main

import "fmt"
import "sort"

var n,s int
var arr []int

var cache[100][100][10] int

var INF = 123456789

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func segment(start, end int) int {
	
	if start == end {
		return 0
	}
	var sum = 0
	
	for i := start; i < end; i++ {
		sum += arr[i]
	}

	var avg = int((float64(sum) / float64(end-start)) + 0.5)

	sum = 0

	for i := start; i < end; i++ {
		sum += (arr[i] - avg) * (arr[i] - avg)
	}

	return sum



}

func solution(pos, prev, rest int) int {
	if pos == n {
		return segment(prev, n)
	}

	if cache[pos][prev][rest] != -1 {
		return cache[pos][prev][rest]
	}
	
	if rest == 0 {
		return segment(prev, n)
	}

	cache[pos][prev][rest] = min(solution(pos+1, prev, rest), segment(prev, pos+1) + solution(pos+1,pos+1, rest - 1))	
	return cache[pos][prev][rest]
}

func main() {
	var C int
	fmt.Scan(&C)
	for TC := 0; TC < C; TC++ {
		fmt.Scan(&n, &s)

		var temp int
		arr = []int{}
		for i := 0; i < n; i++ {
			fmt.Scan(&temp)
			arr = append(arr,temp)
		}
		sort.Ints(arr)
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				for k := 0; k < s; k++ {
					cache[i][j][k] = -1
				}
			}
		}
		fmt.Println(solution(0,0,s-1))
	}
}
