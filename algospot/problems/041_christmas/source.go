package main 

import "fmt"
import "bufio"
import "os"

var psum[100001] int
var count[100000] int

func main() {
		
	var reader = bufio.NewReader(os.Stdin)
	var writer = bufio.NewWriter(os.Stdout)
	var C = 0
	fmt.Fscan(reader,&C)
	for TC := 0; TC < C; TC++ {
		var n,k int
		var cur int

		fmt.Fscan(reader,&n, &k)
		psum[0] = 0

		for i := 0; i < n; i++ {
			fmt.Fscan(reader,&cur)
			psum[i+1] = (cur + psum[i]) % k
		}

		for i := 0; i < k; i++ {
			count[i] = 0
		}

		var ans_1 = 0
		for i := 0; i <= n; i++ {
			ans_1 += count[psum[i]]
			ans_1 %= 20091101
			count[psum[i]]+=1
		}

		var ans_2 = 0
		
		var pos = 0
		var end = n+1

		for ; pos <= n; {
			
			if pos == end {
				ans_2 += 1
				end = n+1
			}

			for i := pos+1;i < end; i++ {
				if psum[pos] == psum[i] {
					end = i
					break
				}
			}

			pos+=1
		}


		fmt.Fprintf(writer,"%d %d\n",ans_1, ans_2)


	}
	writer.Flush()
}
