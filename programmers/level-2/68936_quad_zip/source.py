def solution(arr):
    size = len(arr)

    check = [[1 for _ in range(size)] for _ in range(size)]
    cur_size = 1
    while True:
        if cur_size == size:
            break

        for i in range(0, size, cur_size*2):
            for j in range(0, size, cur_size*2):
                cur_bit = arr[i][j]
                cur_check = check[i][j]
                cond = True
                for y in range(0, cur_size*2, cur_size):
                    for x in range(0, cur_size*2, cur_size):
                        if cur_check != check[i+y][j+x]:
                            cond = False
                            break
                        if cur_bit != arr[i+y][j+x]:
                            cond = False
                            break
                if cond:
                    check[i][j] = cur_size*2
        cur_size *= 2

    cur_size = size
    count_1 = 0
    count_2 = 0
    while True:
        if cur_size == 0:
            break
        for i in range(size):
            for j in range(size):
                if check[i][j] == cur_size:
                    if arr[i][j] == 1:
                        count_1 += 1
                    else:
                        count_2 += 1
                    for y in range(cur_size):
                        for x in range(cur_size):
                            check[i+y][j+x] = 0
        cur_size = cur_size // 2

    return [count_2, count_1]

size = 16
arr = [
    [1, 1, 0, 0],
[1, 1, 0, 0],
[0, 0, 1, 1],
[0, 0, 1, 1],
]
print(solution(arr))