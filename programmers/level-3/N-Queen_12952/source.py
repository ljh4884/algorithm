from collections import defaultdict


def solution(values, edges, queries):
    answer = []
    val_sum = defaultdict(lambda: 0)
    val = {}
    par = {}

    for i, v in enumerate(values):
        val[i + 1] = v
        val_sum[i + 1] = v
    for (p, s) in edges:
        par[s] = p
    par[1] = 1
    for i, v in enumerate(values):
        if i == 0:
            continue
        p = par[i + 1]
        while True:
            val_sum[p] += v
            if p == 1:
                break
            p = par[p]

    for (index,op) in queries:
        if op == -1:
            answer.append(val_sum[index])
        else:
            p = index
            temp = val[index]
            while True:

                if p == 1:
                    val[1] = op
                    val_sum[1] += op
                    val_sum[1] -= temp
                    break
                val[p] = val[par[p]]
                val_sum[p] -= temp
                val_sum[p] += val[par[p]]
                p = par[p]
    for i in range(len(values)):
        print(val[i+1])
    return answer

if __name__ == '__main__':
    values = [1,10,100,1000,10000]
    edges = [[1,2],[1,3],[2,4],[2,5]]
    queries = [[1,-1],[2,-1],[3,-1],[4,-1],[5,-1],[4,1000],[1,-1],[2,-1],[3,-1],[4,-1],[5,-1],[2,1],[1,-1],[2,-1],[3,-1],[4,-1],[5,-1]]
    result = solution(values, edges, queries)
    print(result)

