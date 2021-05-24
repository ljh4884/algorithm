package main

import "fmt"

var n, p, l int64

type gbox struct {
	left *gbox
	mid *string
	right *gbox

	length int64
}
var i string = "FX"
var a string = "FX+YF"
var b string = "FX-YF"
var plus string = "+"
var minus string = "-"

var cache [51]*gbox

func solve (g int64) *gbox {
	if cache[g] != nil {
		return cache[g]
	}
	if g == 0 {
		return &gbox{nil, &i, nil, 2}
	}
	if g == 1 {
		return &gbox{nil, &a, nil, 5}
	}
	if g == 2 {
		return &gbox{solve(1), &plus, &gbox{nil, &b, nil, 5}, 11}
	}
	prev := solve(g-1)
	cache[g] = &gbox{prev, &plus, &gbox{prev.left, &minus, prev.right, prev.length}, prev.length * 2 + 1}

	return cache[g]
}
func solve2(g *gbox, p, l int64) {
	if g.left == nil {
		//fmt.Println("base", p, l)
		fmt.Print((*g.mid)[p:p+l])
		return
	}
	half := g.length / 2
	//fmt.Println(p, half, l)
	fmt.Println(p,l)
	if p == half {
		fmt.Print(*g.mid)
		solve2(g.right, 0, l-1)
	} else if p >= half+1 {
		solve2(g.right, p-half-1, l)
	} else if p + l == half + 1 {
		solve2(g.left, p, l-1)
		fmt.Print(*g.mid)
	} else if p + l <= half {
		solve2(g.left, p, l)
	} else {
		solve2(g.left, p, half-p)
		fmt.Print(*g.mid)
		solve2(g.right, 0, l-(half-p+1))
	}
}
func main() {
	c := 0

	fmt.Scan(&c)

	for ; c > 0; c-- {
		fmt.Scan(&n, &p, &l)
		solve2(solve(n), p-1, l)
		fmt.Println()

		// p 1부터 시작 p-1로 
	}
}
