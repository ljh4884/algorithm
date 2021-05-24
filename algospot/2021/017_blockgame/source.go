package main

import (
	"fmt"
	. "fmt"
)
const (
	WIN = iota+1
	LOSE
	NOT_END
	ALL_OCCUPIED
)
var I_BLOCK = [2][2]int {
	{1, 0},
	{0, 1},
}
var L_BLOCK = [4][2][2]int {
	{
		{0, 1},
		{1, 1},
	},
	{
		{1, 0},
		{1, 1},
	},
	{
		{1, 0},
		{1, -1},
	},
	{
		{0, 1},
		{1, 0},
	},
}
var cache[2 << 25]byte
var MAP [5][5]rune

func canPut(y, x, t int) bool {
	if t < 4 {
		nextY1 := y + L_BLOCK[t][0][0]
		nextX1 := x + L_BLOCK[t][0][1]
		nextY2 := y + L_BLOCK[t][1][0]
		nextX2 := x + L_BLOCK[t][1][1]
		
		if nextY1 < 5 && nextX1 < 5 && nextY2 < 5 && nextX2 < 5 && nextX2 >= 0 &&
		MAP[nextY1][nextX1] == '.' && MAP[nextY2][nextX2] == '.' {
			return true
		}
		return false
	}
	t -= 4
	nextY := y + I_BLOCK[t][0]
	nextX := x + I_BLOCK[t][1]

	if nextX < 5 && nextY < 5 && MAP[nextY][nextX] == '.' {
		return true
	}
	return false

}

func Put(y, x, t int) {
	if t < 4 {
		nextY1 := y + L_BLOCK[t][0][0]
		nextX1 := x + L_BLOCK[t][0][1]
		nextY2 := y + L_BLOCK[t][1][0]
		nextX2 := x + L_BLOCK[t][1][1]
		MAP[y][x] = '#'
		MAP[nextY1][nextX1] = '#'
		MAP[nextY2][nextX2] = '#'

	} else {
		t -= 4
		nextY := y + I_BLOCK[t][0]
		nextX := x + I_BLOCK[t][1]
		MAP[y][x] = '#'
		MAP[nextY][nextX] = '#'
	}
}
func UnPut(y, x, t int) {
	if t < 4 {
		nextY1 := y + L_BLOCK[t][0][0]
		nextX1 := x + L_BLOCK[t][0][1]
		nextY2 := y + L_BLOCK[t][1][0]
		nextX2 := x + L_BLOCK[t][1][1]
		MAP[y][x] = '.'
		MAP[nextY1][nextX1] = '.'
		MAP[nextY2][nextX2] = '.'

	} else {
		t -= 4
		nextY := y + I_BLOCK[t][0]
		nextX := x + I_BLOCK[t][1]
		MAP[y][x] = '.'
		MAP[nextY][nextX] = '.'
	}
}
func check() (int, int, int) {
	for y := 0; y < 5; y++ {
		for x := 0; x < 5; x++ {
			if MAP[y][x] == '.' {
				for t := 0; t < 6; t++ {
					if canPut(y, x, t) {
						return NOT_END, y, x
					}
				}
			}
		}
	}
	return ALL_OCCUPIED, -1, -1 
}
func MapToInt() int {
	status := 0
	tmp := 1
	for y := 0; y < 5; y ++ {
		for x := 0; x < 5; x++ {
			if MAP[y][x] == '#' {
				status += tmp << (5 * uint(y) + uint(x))
			}
		}
	}
	return status
}
func solve2() byte {
	status := MapToInt()
	res, y, x := 0, 0, 0

	if cache[status] > 0 {
		return cache[status]
	}
	if res, y, x = check(); res == ALL_OCCUPIED {
		cache[status] = LOSE
		return LOSE
	}

	for ; y < 5; y++ {
		for ; x < 5; x ++ {
			if MAP[y][x] == '.' {
//				fmt.Println("candi :",y, x)
				for t := 0; t < 6; t++ {
					if canPut(y, x, t) {

						Put(y, x, t)

//						fmt.Println("put", y, x, t)
//						PrintMap()

						nextPlayerResult := solve2()

						UnPut(y, x, t)
//						fmt.Println("unput", y, x, t)
//						if nextPlayerResult == WIN {
//							fmt.Println("Me : LOSE")
//						} else {
//							fmt.Println("Me : WIN")

//						PrintMap()
						if nextPlayerResult == LOSE {
							cache[status] = WIN
							return WIN
						}
					}
				}
			}

		}
		x = 0
	}
	return LOSE
}
func PrintMap() {
	for i := 0; i < 5; i++ {
		for j := 0; j < 5; j++ {
				fmt.Printf("%c",MAP[i][j])
		}
		fmt.Println()
	}
}
func main() {
	c := 0
	Scan(&c)

	for ; c > 0; c-- {
		tmp := ""
		for i := 0; i < 5; i++ {
			Scan(&tmp)

			for j, v := range tmp {
				MAP[i][j] = v
			}
		}
		if res := solve2(); res == WIN {
			fmt.Println("WINNING")
		} else {
			fmt.Println("LOSING")
		}
	}
}
