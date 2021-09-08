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
	var size = 5000001
	var queue = make([]int, size)
	fmt.Scan(&C)
	for TC := 0; TC < C; TC++ {
		var k,n int
		fmt.Scan(&k, &n)


		var A = 1983
		var num = 1984
		var psum = 1984
		
		var ret = 0

		var head = 0
		var tail = 1

	
		queue[0] = 1984

		for i := 0; i < n; i++ {
			if psum > k {
				for ; ; {
					
					if psum <= k {
						break
					}

					psum -= queue[head]
					head = (head + 1)%size
					
				}
			}

			if psum == k {
				ret += 1
				psum -= queue[head]
				head = (head + 1)%size
			}

			A = next_A(A)
			num = A2num(A)
			psum += num
			queue[tail] = num
			tail = (tail+1)%size
		}

		fmt.Println(ret)
	}
}
