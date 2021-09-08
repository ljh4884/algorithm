package main

import "fmt"

type Queue struct {
        head, tail int
        q          []int
}

func (q *Queue) init(size int) {
        q.head, q.tail = 0, 1
        q.q = make([]int, size)
}
func (q *Queue) push(x int) {
        q.q[q.tail] = x
        q.tail = (q.tail + 1) % len(q.q)
}
func (q *Queue) pop() int {
        q.head = (q.head + 1) % len(q.q)
        return q.q[q.head]
}

var (
        t, n, k int
)

func main() {

        fmt.Scan(&t)
        queue := new(Queue)
        queue.init(5000002)

        for ; t > 0; t-- {
                fmt.Scan(&k, &n)

                sum := 0
                answer := 0
                queue.head, queue.tail = 0, 1
                a, b := 1983, 1983

                for i := 0; i < n; i++ {
                        a = b
                        b = (a*214013 + 2531011) % (1 << 32)
                        signal := a%10000 + 1
                        queue.push(signal)
                        sum += signal

                        for sum > k {
                                sum -= queue.pop()
                        }

                        if sum == k {
                                answer++
                        }
                }
                fmt.Println(answer)
        }
}
