package main

import "fmt"

var h,w int
var table[20][20] int
var end int

func solve(count int) int {
	if count == end {
		return 1
	}

	var cond = false
	var ret = 0

	for i := 0; i < h; i++ {
		for j := 0; j < w; j++{
			if table[i][j] == 0 {
				table[i][j] = 1
				if j != 0 && i != h-1 {
					if table[i+1][j] == 0 && table[i+1][j-1] == 0 {
						table[i+1][j] = 1
						table[i+1][j-1] = 1
						ret += solve(count+3)
						table[i+1][j] = 0
						table[i+1][j-1] = 0
						
						cond = true
					}
				}

				if j != w-1 && i != h-1 {
					if table[i+1][j] == 0 && table[i][j+1] == 0 {
						table[i+1][j] = 1
						table[i][j+1] = 1
						ret += solve(count+3)
						table[i][j+1] = 0
						table[i+1][j] = 0
						
						cond = true
					}

					if table[i+1][j] == 0 && table[i+1][j+1] == 0 {
						table[i+1][j] = 1
						table[i+1][j+1] = 1
						ret += solve(count+3)
						table[i+1][j] = 0
						table[i+1][j+1] = 0
						
						cond = true
					}


					if table[i][j+1] == 0 && table[i+1][j+1] == 0 {
						table[i][j+1] = 1
						table[i+1][j+1] = 1
						ret += solve(count+3)
						table[i][j+1] = 0
						table[i+1][j+1] = 0
						
						cond = true
					}




				}
				table[i][j] = 0
				if cond == false {
					return 0
				}
				break
			}
		}
		if cond == true {
			break
		}
	}
	return ret
}

func main() {
	var C int
	fmt.Scan(&C)

	for TC := 0; TC < C; TC++ {
		fmt.Scan(&h, &w)
		end = 0

		var str string

		for i := 0; i < h; i++ {
			fmt.Scan(&str)
			for j := 0; j < w; j++ {
				if str[j] == '.' {
					table[i][j] = 0
					end += 1
				} else {
					table[i][j] = 1
				}
				
			}
		}
		fmt.Println(solve(0))
		

	}
}
