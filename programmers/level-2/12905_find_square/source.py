def solution(board):
    max_value = 1

    row = len(board)
    col = len(board[0])

    for i in range(row):
        for j in range(col):
            if board[i][j] == 1:
                size = max_value + 1

                if i + size - 1 >= row:
                    continue

                if j + size - 1 >= col:
                    continue

                check = False
                for y in range(size):
                    if check:
                        break
                    for x in range(size):
                        if board[i+y][j+x] == 0:
                            check = True
                            break
                if check:
                    continue
                max_value = size
                while True:
                    if i + size >= row:
                        break
                    if j + size >= col:
                        break

                    for k in range(size+1):
                        if board[i+size][j+k] == 0:
                            check = True
                            break
                        if board[i+k][j+size] == 0:
                            check = True
                            break

                    if check:
                        break

                    size += 1
                    max_value = size

    return max_value**2


board = 	[[1,1],[1,1]]

print(solution(board))