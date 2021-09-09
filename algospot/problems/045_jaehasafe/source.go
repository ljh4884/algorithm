package main

import "fmt"

func main() {
	var C = 0
	fmt.Scan(&C)

	for TC := 0; TC < C; TC++ {
		var n int
		fmt.Scan(&n)

		var prev,next string
		fmt.Scan(&prev)
		var size = len(prev)


		var turn = true
		var ret = 0
		for i := 0; i < n; i++ {
			fmt.Scan(&next)
			temp = prev + prev

			index = 1
			for {
				if index == size+1 {
					break
				}
				if temp[index] == next[0] {
					
				}
			}

			if turn == true {
				for index := 1; index <= size; index++ {
					if (prev[size-index:] == next[:index]) && (prev[:size-index] == next[index:]) {
						ret += index
						break
					}
				}
			} else {
				for index := 1; index <= size; index++ {
					if (prev[:index] == next[size-index:]) && (prev[index:] == next[:size-index]) {
						ret += index
						break
					}
				}
			
			}
			
			turn = !turn
			prev = next
		}

		fmt.Println(ret)
	}
}
