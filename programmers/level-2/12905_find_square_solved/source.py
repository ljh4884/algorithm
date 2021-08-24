

def solution(board):
    row = len(board)
    col = len(board[0])

    answer = 0

    sub_sum = [[0 for _ in range(col+1)] for _ in range(row+1)]
    for i in range(1, row+1):
        for j in range(1, col+1):
            sub_sum[i][j] = board[i-1][j-1] + sub_sum[i-1][j] + sub_sum[i][j-1] - sub_sum[i-1][j-1]
    size = 0
    for i in range(row):
        for j in range(col):
            size = answer + 1
            for size in range(answer+1, row+1):
                if i + size > row:
                    break
                if j + size > col:
                    break
                temp = 0
                temp += sub_sum[i][j]
                temp -= sub_sum[i+size][j]
                temp -= sub_sum[i][j+size]
                temp += sub_sum[i+size][j+size]

                if temp == size**2:
                    answer = size
                else:
                    break

    return answer**2

board = [[0,0,1,1],[1,1,1,1]]
#board = [[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]
print(solution(board))