package main

import "fmt"
import "sort"


var n int
var target string
var str string
var answer []string

func solve(t_pos, s_pos int) bool {
	
	if s_pos == len(str) {
		for i := t_pos; i < len(target); i++ {
			if target[i] != '*' {
				return false
			}
		}
		return true
	}

	if t_pos == len(target) {
		if target[t_pos-1] == '*' {
			return true
		}
		return false
	}

	if target[t_pos] == '*' {
		var ret = false
		for i := s_pos; i < len(str); i++ {
			ret = ret || solve(t_pos+1, i)
		}
		return ret
	}

	if (target[t_pos] == str[s_pos]) || (target[t_pos] == '?') {
		return solve(t_pos+1, s_pos + 1)
	}

	return false

}

func main() {
	var C int
	fmt.Scan(&C)
	for TC := 0; TC < C; TC++ {
		fmt.Scan(&target, &n)
		answer = []string{}
		for i := 0; i < n; i++ {
			fmt.Scan(&str)

			if solve(0, 0) == true {
				answer = append(answer, str)
			}
		}
		sort.Strings(answer)
		for i := 0; i < len(answer); i++ {
			fmt.Println(answer[i])
		}
	}
}

