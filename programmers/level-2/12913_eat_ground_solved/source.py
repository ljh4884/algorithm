import sys
cache = []
land = []

sys.setrecursionlimit(200000)
def func(y, prev_x):
    if y == len(land):
        return 0
    if cache[y][prev_x] != -1:
        return cache[y][prev_x]

    ret = 0

    for i in range(4):
        if i == prev_x:
            continue
        ret = max(ret, land[y][i] + func(y+1, i))

    cache[y][prev_x] = ret
    return ret


def solution(land2):
    global cache
    global land

    cache = [[-1 for _ in range(4)] for _ in range(len(land2))]
    land = [[seg for seg in lan] for lan in land2]
    answer = 0

    for i in range(4):
        answer = max(answer, land[0][i] + func(1, i))

    return answer


if __name__ == "__main__":
    land = [[i*4 + j for j in range(4)] for i in range(10000)]
    print(solution(land))