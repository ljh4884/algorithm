package main

import "fmt"
import "os"
import "bufio"

var n,k int
var arr [500]int

var cache[501] int
var cache_2[501] int

type data struct {
	key int
	value int
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve(pos int) int {
	
	var std = 0
	if pos == -1 {
		std = -(1<<32)
	} else {
		std = arr[pos]
	}

	if pos == n-1 {
		return 0
	}

	if cache[pos+1] != -1 {
		return cache[pos+1]
	}

	var ret = 0
	for i := pos + 1; i < n; i++ {
		if std < arr[i] {
			ret = max(ret, 1 + solve(i))
		}
	}
	cache[pos+1] = ret
	return ret
}

func count(pos int) int {
	
	var std = 0
	if pos == -1 {
		std = -(1<<32)
	} else {
		std = arr[pos]
	}

	if solve(pos) == 0 {
		return 1
	}

	if cache_2[pos+1] != -1 {
		return cache_2[pos+1]
	}

	var ret = 0
	for i := pos + 1; i < n; i++ {
		if (arr[i] > std) && (solve(pos) == 1 + solve(i)) {
			ret += count(i)
		}
	}

	cache_2[pos+1] = ret
	return ret
}

func display(pos int) {
	
	var std int
	if pos == -1 {
		std = -(1<<32)
	} else {
		std = arr[pos]
	}
	var info = make([]data, 0)
	for i := pos + 1; i < n; i++ {
		if (std  < arr[i]) && (solve(pos) == 1 + solve(i)) {
			info = append(info, data{arr[i], i})
		}
	}
	


	for i := len(info)-1; i > -1; i-- {
		if k - count(info[i].value) <= 0 {
			fmt.Print(info[i].key, " ")
			display(info[i].value)
			break
		} else {
			k -= count(info[i].value)
		}
	}

}

func main() {
	var reader = bufio.NewReader(os.Stdin)

	var C int
	fmt.Fscan(reader, &C)

	for TC := 0; TC < C; TC++ {
		fmt.Fscan(reader, &n, &k)

		for i := 0; i < n; i++ {
			fmt.Fscan(reader, &arr[i])
			cache[i] = -1
			cache_2[i] = -1
		}
		cache[n] = -1
		cache_2[n] = -1
		
		display(-1)
		fmt.Println()
	}
}
