package main

import "fmt"

const mul int64 = int64(214013)
const bias int64 = int64(2531011)
const mod int64 = int64((1<<32))

func next_A(prev int) int {
	var ret = int64(prev)
	return int((ret * mul + bias) % mod)
}

func A2num(A int) int {
	return A%10000 + 1
}

func main() {
	var C = 0
	fmt.Scan(&C)
	for TC := 0; TC < C; TC++ {
		var k, n int
		fmt.Scan(&k, &n)

		var A = 1983
		var num = 1984
		
		var ret = 0
		var psum = 1984

		var queue = []int{1984}
		for i := 1; i <= n; i++ {
			if psum > k {
				for ; ; {
					if (psum <= k) || (len(queue) == 0){
						break
					}
					psum -= queue[0]
					queue = queue[1:]
				}
			}

			if psum == k {
				ret += 1
				psum = 0
				queue = []int{}
			}
			A = next_A(A)
			num = A2num(A)
			queue = append(queue, num)
			psum += num
		}


		fmt.Println(ret)


	}
}
