package main

import "fmt"

var cache[101] int
var cache2[101] int
var div = 1000000007 
var n int


func main() {
	var C = 0
	fmt.Scan(&C)

	cache[0] = 1
	cache[1] = 1
	cache[2] = 2
	
	for i := 3; i < 101; i++ {
		cache[i] = (cache[i-1] + cache[i-2]) % div
	}
	var temp = 0
	cache2[1] = 0
	cache2[2] = 0
	for i := 3; i < 101; i++ {
		temp = (cache[i] - cache[i/2])%div
		if temp < 0 {
			temp += div
		}
		if i % 2 == 0 {
			temp -= cache[i/2 - 1]
			if temp < 0 {
				temp += div
			}
			temp = temp % div
		} 
		cache2[i] = temp
	}

	for TC := 0; TC < C; TC++ {
		fmt.Scan(&n)

		fmt.Println(cache2[n])
	}
}
