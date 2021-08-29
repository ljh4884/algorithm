package main

import "fmt"

var clock[16] int
var way[10] []int

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func check() int {
	for i := 0; i < 16; i++ {
		if clock[i] != 12 {
			return 0
		}
	}
	return 1
}

func front(pick []int) {

	for i := 0; i < len(pick); i++ {
		clock[pick[i]] = clock[pick[i]] % 12 + 3 
	}
	return
}

func back(pick []int) {
	for i := 0; i < len(pick); i++ {
		clock[pick[i]] = (clock[pick[i]] + 6) % 12 + 3
	}
}

func solve(pos int) int {
	
	var ret = 10000000

	if pos == 10{
		if check() == 1 {
			return 0
		} else {
			return 10000000
		}
	}
	for i := 0; i < 4; i++ {
		ret = min(ret, i + solve(pos+1))
		front(way[pos])
	}
	return ret
}

func main() {
	
	way[0] = []int{0,1,2}
	way[1] = []int{3,7,9,11}
	way[2] = []int{4,10,14,15}
	way[3] = []int{0,4,5,6,7}
	way[4] = []int{6,7,8,10,12}
	way[5] = []int{0,2,14,15}
	way[6] = []int{3,14,15}
	way[7] = []int{4,5,7,14,15}
	way[8] = []int{1,2,3,4,5}
	way[9] = []int{3,4,5,9,13}


	var C = 0
	fmt.Scan(&C)
	for TC := 0; TC < C; TC++ {
		for i := 0; i < 16; i++ {
			fmt.Scan(&clock[i])
		}

		var ret = solve(0);

		if ret < 10000000 {
			fmt.Println(ret)
		} else {
			fmt.Println(-1)
		}

	}

} 
