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
var index_to_word = map[int]string{}


func main() {
	var reader = bufio.NewReader(os.Stdin)
	var writer = bufio.NewWriter(os.Stdout)

	fmt.Fscan(reader, &m, &q)

	for i := 0; i < m; i++ {
		fmt.Fscan(reader, str[i])
		fmt.Fprint(writer, str[i])
		word_to_index[str[i]] = i
		index_to_word[i] = str[i]
	}




}
