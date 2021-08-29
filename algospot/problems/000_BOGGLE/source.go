package main
import "fmt"


var table[5] string
var N int
var str string
var cache[10][5][5] int
var n = 0
func solve(pos, y, x int) int {
	
	if pos == n {
		return 1
	}

	if y == 5 || x == 5 || y == -1 || x == -1 {
		return 0
	}

	if cache[pos][y][x] != -1 {
		return cache[pos][y][x]
	}

	if table[y][x] != str[pos] {
		cache[pos][y][x] = 0
		return 0
	}
	
	var ret int
	ret = 0
	for i := -1; i < 2; i++ {
		for j := -1; j < 2; j++ {
			if i == 0 && j == 0 {
				continue
			}
			ret = ret | solve(pos+1, y+i, x+j)
		}
	}

	cache[pos][y][x] = ret
	return ret

}


func main() {

	var C int
	fmt.Scan(&C)

	for TC := 0; TC < C; TC++ {
	
		for i := 0; i < 5; i++ {
			fmt.Scan(&table[i])
		}

		fmt.Scan(&N)

		for cnt := 0; cnt < N; cnt++ {
			fmt.Scan(&str)
			n =  len(str)
			for i := 0; i < 10; i++ {
				for j := 0; j < 5; j++ {
					for k := 0; k < 5; k++ {
						cache[i][j][k] = -1
					}
				}
			}
			var ret = 0
			for i := 0; i < 5; i++ {
				for j := 0; j < 5; j++ {
					if table[i][j] == str[0] {
						ret = ret | solve(0, i, j)
					}
					if ret == 1 {
						break
					}
				}
			}

			fmt.Printf(str)
			if ret == 1 {
				fmt.Println(" YES")
			} else {
				fmt.Println(" NO")
			}



		}

	}

}
