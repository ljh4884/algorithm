
def solution(n, edge):
    answer = 0
    INF = 20002

    arr = [[INF for _ in range(n+1)] for _ in range(n+1)]

    for i in range(1, n+1):
        arr[i][i] = 0

    for (start, end) in edge:
        arr[start][end] = 1
        arr[end][start] = 1

    visit = [0 for _ in range(n+1)]
    dis = [INF for _ in range(n+1)]

    dis[1] = 0
    for i in range(2, n+1):
        dis[i] = arr[1][i]

    visit[1] = 1





    return answer

if __name__ == "__main__":
    n = 6
    edge = [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]
    print(solution(n, edge))