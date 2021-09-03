package main

import "fmt"

var str string
var n int
var INF = 12345678

var cache[10001] int

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func segment(pos, size int) int {
	var comp = str[pos]
	var cond = true
	var ret = INF
	for i := pos+1; i < pos+size; i++ {
		if comp != str[i] {
			cond = false
			break
		}
	}
	if cond == true {
		ret = min(ret, 1 + solve(pos+size))
	}

	cond = true
	var step = int(str[pos+1]) - int(str[pos])
	for i := pos+1; i < pos + size - 1; i++ {
		if int(str[i+1]) - int(str[i]) != step {
			cond = false
			break
		}
	}

	if cond == true {
		if (step == 1) || (step == -1) {
			ret = min(ret, 2 + solve(pos+size))
		} else {
			ret = min(ret, 5 + solve(pos+size))
		}
	}

	cond = true
	for i := pos; i < pos+size-2; i++ {
		if str[i] != str[i+2] {
			cond = false
			break
		}
	}
	if cond == true {
		ret = min(ret, 4 + solve(pos+size))
	}
	ret = min(ret, 10 + solve(pos+size))
	return ret
}

func solve(pos int) int {
	if pos == n {
		return 0
	}
	if pos + 3 > n {
		return INF
	}

	if cache[pos] != -1 {
		return cache[pos]
	}

	var ret = INF

	if n - pos > 2 {
		ret = segment(pos, 3)
	}

	if n - pos > 3 {
		ret = min(ret, segment(pos, 4))
	}

	if n - pos > 4 {
		ret = min(ret, segment(pos, 5))
	}
	cache[pos] = ret
	return ret
}

func main() {
	var C int
	fmt.Scan(&C)
	for TC := 0; TC < C; TC++ {
		fmt.Scan(&str)
		n = len(str)

		for i := 0; i < n; i++ {
			cache[i] = -1
		}
		fmt.Println(solve(0))
	}
}
