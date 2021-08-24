def solution(dirs):
    answer = 0
    pos_x = 0
    pos_y = 0

    check = []
    for d in dirs:
        if d == "L":
            if pos_x == -5:
                continue
            temp = [(pos_x-1, pos_y), (pos_x, pos_y)]
            pos_x -= 1
            if temp in check:
                continue

            check.append(temp)
            answer += 1
        elif d == "R":
            if pos_x == 5:
                continue
            temp = [(pos_x, pos_y), (pos_x+1, pos_y)]
            pos_x += 1
            if temp in check:
                continue

            check.append(temp)
            answer += 1
        elif d == "U":
            if pos_y == 5:
                continue
            temp = [(pos_x, pos_y), (pos_x, pos_y+1)]
            pos_y += 1
            if temp in check:
                continue

            check.append(temp)
            answer += 1

        else:
            if pos_y == -5:
                continue
            temp = [(pos_x, pos_y-1), (pos_x, pos_y)]
            pos_y -= 1
            if temp in check:
                continue

            check.append(temp)
            answer += 1

    return answer