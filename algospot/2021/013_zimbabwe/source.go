package main

import "fmt"
const d = 1000000007

var e uint64
var m int
var cache map[[10]int]int
var length int
var cntList [10]int
var numList []int

func solve1() {
	length = 0
	cntList = [10]int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

	for tmp := e; tmp != 0; tmp /= 10 {
		length++
	}
	numList = make([]int, length)

	for idx := length-1; e != 0; e, idx = e / 10, idx-1 {
		num := e % 10
		cntList[num] += 1
		numList[idx] = int(num)
	}
	/*
	fmt.Println(length)
	fmt.Println(cntList)
	fmt.Println(numList)
	*/
}
func solve2(prev int) int {
	ret := 0
	start := 0

	fmt.Println(prev)
	if prev == 0 && cache[cntList] > 0 {
		return cache[cntList]
	}

	for ; start < 10; start++ {
		if cntList[start] != 0 {
			break
		}
	}
	if start == 10 && prev == 0 {
		return 1
	}
	for num := start; num < 10; num++ {
		if cntList[num] == 0 {
			continue
		}
		cntList[num] -= 1
		//fmt.Print(num)
		ret += solve2((prev * 10 + num) % m)
		//fmt.Println()
		cntList[num] += 1
	}
	if prev == 0 {
		cache[cntList] = ret
	}
	return ret
}
func solve3(prev, idx int) int{
	ret := 0
	fmt.Println(idx)
	if idx == length {
		return 0
	}

	for num := 0; num < numList[idx]; num++ {
		if cntList[num] > 0 {
			cntList[num] -= 1
			ret = (ret + solve2((prev * 10 + num) % m)) % d
			cntList[num] += 1
		}
	}

	if num := numList[idx]; cntList[num] > 0 {
		cntList[num] -= 1
		ret = (ret + solve3(num, idx+1)) % d
		cntList[num] += 1
	}
	return ret
}
func main() {
	c := 0
	fmt.Scan(&c)


	for ; c > 0; c-- {
		cache = make(map[[10]int]int)
		fmt.Scan(&e, &m)
		solve1()
		fmt.Println(solve3(0, 0),length)
		fmt.Println()
	}
}
