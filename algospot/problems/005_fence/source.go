package main

import "fmt"

var fence[20000] int
var last = 0

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func solve(start,end int) int {
	
	if start == end {
		return fence[start]
	}

	var mid = (start + end) / 2
	
	var l_size, r_size int

	l_size = solve(start,mid)
	r_size = solve(mid+1, end)
	
	var first = max(l_size, r_size)

	var left = mid
	var right = mid+1
	var height = min(fence[left], fence[right])
	var temp = 2 * height
	for ; ; {
		if (left == start) && (right == end) {
			break
		} else if left == start {
			right += 1	
		} else if right == end {
			left -= 1
		} else if fence[right+1] >= fence[left - 1] {
			right += 1
		} else {
			left -= 1
		}
		height = min(height, min(fence[left], fence[right]))
		temp = max(temp, (right - left + 1) * height)
	}


	return max(temp, first)


}

func main() {
	var C = 0

	fmt.Scan(&C)

	for TC := 0; TC < C; TC++ {
		var n = 0
		fmt.Scan(&n)
		for i := 0; i < n; i++ {
			fmt.Scan(&fence[i])
		}
		fmt.Println(solve(0, n-1))
	}
}
