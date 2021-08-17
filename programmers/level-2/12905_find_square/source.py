

def solution(board):
    row = len(board)
    col = len(board[0])
    answer = 0

    for i in range(row):
        for j in range(col):
            if board[i][j] == 1:
                size = answer + 1
                check = True
                for y in range(i, i+size):
                    if not check:
                        break
                    if y >= row:
                        check = False
                        break
                    for x in range(j, j+size):
                        if x >= col:
                            check = False
                            break
                        if board[y][x] == 0:
                            check = False
                            break

                if check:
                    answer = size
                    for k in range(size+1, 1000):
                        check = True
                        if i+k > row:
                            break
                        if j+k > col:
                            break
                        if j+size-1 >= col:
                            break
                        if i+size-1 >= row:
                            break
                        for y in range(i, i+k):
                            if board[y][j+size-1] == 0:
                                check = False
                                break
                        for x in range(j, j+k):
                            if board[i+size-1][x] == 0:
                                check = False
                                break
                        if check:
                            answer = k
                        else:
                            break
                else:
                    continue


    return answer**2

board = [[0,0,1,1],[1,1,1,1]]
#board = [[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]
print(solution(board))