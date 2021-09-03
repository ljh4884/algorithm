package main

import "fmt"

var INF = 123456
var n,k,m,l int

var pre_class[12] int
var sem_class[10] int

var cache[10][1<<12] int

var index = []int{1<<0,1<<1,1<<2,1<<3,1<<4,1<<5,1<<6,1<<7,1<<8,1<<9,1<<10,1<<11,1<<12}


func count_bit(bit int) int {
	var count = 0

	for ; ; {
		if bit == 0 {
			break
		}

		if bit%2 == 1 {
			count += 1
		}

		bit /= 2
	}
	return count
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func solve(pos, bit, sem_count int) int {
	if sem_count >= k {
		return 0
	}

	if pos == m {
		return INF
	}

	if cache[pos][bit] != -1 {
		return cache[pos][bit]
	}

	var ret = solve(pos+1, bit, sem_count)
	
	for cur_bit := 0; cur_bit < index[n]; cur_bit++ {
		if (cur_bit & bit) != 0 {
			continue
		}

		if (cur_bit & sem_class[pos]) != cur_bit {
			continue
		}

		var count = count_bit(cur_bit)

		if count > l {
			continue
		}

		var break_cond = false

		for i := 0; i < n; i++ {
			if (cur_bit & index[i]) != 0 {
				if (pre_class[i] & bit) != pre_class[i] {
					break_cond = true
					break
				}
			}
		}

		if break_cond == false {
			ret = min(ret , 1 + solve(pos+1, bit | cur_bit, sem_count + count))
		}
	}

	cache[pos][bit] = ret
	return ret
	
}

func main() {
	var C = 0
	fmt.Scan(&C)

	for TC := 0; TC < C; TC++ {
		fmt.Scan(&n,&k,&m,&l)

		var count = 0
		var cur_bit = 0
		var class = 0

		for i := 0; i < n; i++ {
			fmt.Scan(&count)
			cur_bit = 0
			for j := 0; j < count; j++ {
				fmt.Scan(&class)
				cur_bit = cur_bit | index[class]
			}
			pre_class[i] = cur_bit
		}

		for i := 0; i < m; i++ {
			fmt.Scan(&count)
			cur_bit = 0
			for j := 0; j < count; j++ {
				fmt.Scan(&class)
				cur_bit = cur_bit | index[class]
			}
			sem_class[i] = cur_bit
		}

		for i := 0; i < m; i++ {
			for j := 0; j < index[n]; j++ {
				cache[i][j] = -1
			}
		}

		var ret = solve(0,0,0)

		if ret > m {
			fmt.Println("IMPOSSIBLE")
		} else {
			fmt.Println(ret)
		}

	}
}
