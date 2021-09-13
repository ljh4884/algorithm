package main
import "fmt"

var n,w int
var name[100] string
var volume[100] int
var want[100] int

var cache[100][1001] int

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve(pos, vol int) int {
	if vol > w {
		return -1000000
	}

	if pos == n {
		return 0
	}

	if cache[pos][vol] != -1 {
		return cache[pos][vol]
	}

	cache[pos][vol] = max(solve(pos+1, vol), want[pos] + solve(pos+1, vol + volume[pos]))
	return cache[pos][vol]


}

func main() {
	var C = 0
	fmt.Scan(&C)
	for TC := 0; TC < C; TC++ {
		fmt.Scan(&n, &w)

		for i := 0; i < n; i++ {
			fmt.Scan(&name[i], &volume[i], &want[i])
		}

		for i := 0; i < n; i++ {
			for j := 0; j <= w; j++ {
				cache[i][j] = -1
			}
		}

		var ret = solve(0, 0)
		var list []string

		var cur_volume = 0
		for i := 0; i < n; i++ {
			if solve(i,cur_volume) != solve(i+1, cur_volume) {
				cur_volume += volume[i]
				list = append(list, name[i])
			}
		}

		fmt.Println(ret, len(list))
		for i := 0; i < len(list); i++ {
			fmt.Println(list[i])
		}
		

	}
}
