package main 

import "fmt"

var n,k int

var arr [100000]int
var seg [200000]int
func main() {
	
	var C = 0
	for TC := 0; TC < C; TC++ {
		fmt.Scan(&n, &k)

		for i := 0; i < n; i++ {
			fmt.Scanf("%d",&arr[i])
		}
	}
}
