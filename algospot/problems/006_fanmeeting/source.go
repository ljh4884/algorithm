// pass if server condition is better

package main

import "fmt"
import "math/big"

func main() {
	var C = 0
	fmt.Scan(&C)

	for TC := 0; TC < C; TC++ {
		var M string
		var F string

		fmt.Scan(&M)
		fmt.Scan(&F)

		var M_byte = make([]byte, len(M))
		var F_byte = make([]byte, len(F))
		for i := 0; i < len(M); i++ {
			if M[i] == 'F' {
				M_byte[i] = '0'
			} else {
				M_byte[i] = '1'
			}
		}

		for i := 0; i < len(F); i++ {
			if F[i] == 'F' {
				F_byte[i] = '0'
			} else {
				F_byte[i] = '1'
			}
		}

		var member,_ = new(big.Int).SetString(string(M_byte), 2)
		var fan,_ = new(big.Int).SetString(string(F_byte), 2)
		
		var count = 0
		
		for i := 0; i < (len(F) - len(M) + 1); i++ {
			if new(big.Int).And(fan,member).Cmp(big.NewInt(0)) == 0 {
				count += 1
			}
			fan.Rsh(fan, 1)
		}

		fmt.Println(count)
			

	}
}
