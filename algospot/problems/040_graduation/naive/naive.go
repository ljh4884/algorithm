package main

import "fmt"

var pre_class[12][12] int // n X n
var sem_class[10][12] int // m X n

var cache[1<<12][10] int

var n,k,m,l int

func count_bit(bit int) int {
	var count = 0
	for ; ; {
		if bit == 0 {
			break
		}
		if bit % 2 == 1 {
			count += 1
		}
		bit /= 2
	}
	return count
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func solve(pos,sem_count, bit int) int {
	if sem_count >= k {
		return 0
	}
	if pos == m {
		return 11
	}

	if cache[bit][pos] != -1 {
		return cache[bit][pos]
	}

	var ret = solve(pos+1, sem_count, bit)

	for cur_bit := 0; cur_bit < (1<<uint(n)); cur_bit++ {
		var break_cond = false
		
		if cur_bit & bit != 0 {
			continue
		}

		var cur_count = count_bit(cur_bit)

		if cur_count > l {
			continue
		}

		for i := 0; i < n; i++ {
			if (cur_bit & (1 << uint(i))) != 0 {
				if sem_class[pos][i] == 0 {
					break_cond = true
					break
				}
				for j := 0; j < n; j++ {
					if pre_class[i][j] == 1 {
						if (bit & (1<<uint(j))) == 0 {
							break_cond = true
							break
						}
					}
				}
			}
		}
		if break_cond == false {
			ret = min(ret, 1+ solve(pos+1, sem_count+cur_count, bit | cur_bit))
		}
	}	
	cache[bit][pos] = ret
	return ret

	
}

func main() {
	var C = 0
	fmt.Scan(&C)
	for TC := 0; TC < C; TC++ {
		fmt.Scan(&n,&k,&m,&l)
		
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				pre_class[i][j] = 0
			}
			for j := 0; j < m; j++ {
				sem_class[j][i] = 0
			}
		}

		for i := 0; i < (1<<uint(n)); i++ {
			for j := 0; j < m; j++ {
				cache[i][j] = -1
			}
		}

		var count = 0
		var class = 0
		for i := 0; i < n; i++ {
			fmt.Scan(&count)
			for j := 0; j < count; j++ {
				fmt.Scan(&class)
				pre_class[i][class] = 1
			}
		}

		for i := 0; i < m; i++ {
			fmt.Scan(&count)
			for j := 0; j < count; j++ {
				fmt.Scan(&class)
				sem_class[i][class] = 1
			}
		}
		var ret = solve(0,0,0)
		if ret > m {
			fmt.Println("IMPOSSIBLE")
		} else {
			fmt.Println(solve(0,0,0))
		}

	}
}
