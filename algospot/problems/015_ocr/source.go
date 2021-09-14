package main

import "fmt"
import "os"
import "bufio"


var m,q int
var str[500] string
var first_word_prob[500] float64
var next_word_prob[500][500] float64
var diff_word_prob[500][500] float64
var n int
var cur_str[500] string

var word_to_index = map[string]int{}

var cache[100][501] float64


func max(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

func solve(pos, prev int) float64 {
	if pos == n {
		return 1.0
	}
	if cache[pos][prev+1] > -0.5 {
		return cache[pos][prev+1]
	}
	var ret = -1.0

	var prob_1 = 1.0
	var prob_2 = 1.0
	for i := 0; i < m; i++ {
		if pos == 0 {
			prob_1 = first_word_prob[i]
		} else {
			prob_1 = next_word_prob[prev][i]
		}
		prob_2 = diff_word_prob[i][word_to_index[cur_str[pos]]]
		
		ret = max(ret, prob_1 * prob_2 * solve(pos+1, i))
		
	}

	
	cache[pos][prev+1] = ret
	return ret
}

func display(pos , prev int) {
	if pos == n {
		fmt.Println()
		return
	}
	var prob_1 = 1.0
	var prob_2 = 1.0

	for i := 0; i < m; i++ {
		if pos == 0 {
			prob_1 = first_word_prob[i]
		} else {
			prob_1 = next_word_prob[prev][i]
		}
		prob_2 = diff_word_prob[i][word_to_index[cur_str[pos]]]

		if solve(pos, prev) == prob_1 * prob_2 * solve(pos+1, i) {
			fmt.Print(str[i], " ")
			display(pos+1, i)
			break
		}
	}
	return

}

func main() {
	var reader = bufio.NewReader(os.Stdin)
	//var writer = bufio.NewWriter(os.Stdout)

	fmt.Fscan(reader, &m, &q)

	for i := 0; i < m; i++ {
		fmt.Fscan(reader,&str[i])
		word_to_index[str[i]] = i
	}

	for i := 0; i < m; i++ {
		fmt.Fscan(reader, &first_word_prob[i])
	}

	for i := 0; i < m; i++ {
		for j := 0; j < m; j++ {
			fmt.Fscan(reader, &next_word_prob[i][j])
		}
	}

	for i := 0; i < m; i++ {
		for j := 0; j < m; j++ {
			fmt.Fscan(reader, &diff_word_prob[i][j])
		}
	}

	for TC := 0; TC < q; TC++ {
		fmt.Fscan(reader, &n)
		for i := 0; i < n; i++ {
			fmt.Fscan(reader, &cur_str[i])
		}
		for i := 0; i < n; i++ {
			for j := 0; j <= m; j++ {
				cache[i][j] = -1.0
			}
		}
		solve(0,-1)
		display(0,-1)
	}





}
