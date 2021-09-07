package main

import "fmt"

func main() {
	var C = 0
	fmt.Scan(&C)
	for TC := 0; TC < C; TC++ {
		var stack = []byte{}
		var str string

		fmt.Scan(&str)
		
		var ret = "YES"

		for i := 0; i < len(str); i++ {
			if str[i] == '(' {
				stack = append(stack, ')')
			} else if str[i] == '{' {
				stack = append(stack, '}')
			} else if str[i] == '[' {
				stack = append(stack, ']')
			} else {
				if len(stack) == 0 {
					ret = "NO"
					break
				}
				if stack[len(stack) - 1] == str[i] {
					stack = stack[:len(stack) - 1]
				} else {
					ret = "NO"
					break
				}
			}
		}

		if len(stack) != 0 {
			ret = "NO"
		}

		fmt.Println(ret)
		
	}
}
