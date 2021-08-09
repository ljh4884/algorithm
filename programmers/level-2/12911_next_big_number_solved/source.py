def solution(n):
    answer = 0

    arr = []
    num = n
    while True:
        if num == 0:
            break

        if num % 2 == 0:
            arr.append(0)
        else:
            arr.append(1)
        num = num // 2
    arr.append(0)
    check = False
    pivot = 0
    count = 0
    for i in range(len(arr)):
        if check == False:
            if arr[i] == 1:
                check = True
        else:
            if arr[i] == 0:
                pivot = i
                arr[i] = 1
                break
            else:
                count += 1
    for i in range(pivot):
        if count > 0:
            arr[i] = 1
            count -= 1
        else:
            arr[i] = 0
    mul = 1
    for i in range(len(arr)):
        if arr[i] == 1:
            answer += mul
        mul *= 2

    return answer

print(solution(78))