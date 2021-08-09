

def solution(arr):
    answer = 0

    count = [0 for i in range(101)]

    for a in arr:
        num = a
        div = 2
        temp_count = [0 for i in range(101)]
        while True:
            if num == 1:
                break
            if num % div == 0:
                num = num // div
                temp_count[div] += 1
                div = 2
                continue
            div += 1
        for i in range(101):
            count[i] = max(count[i], temp_count[i])

    answer = 1

    for i in range(101):
        for j in range(count[i]):
            answer *= i

    return answer


if __name__ == '__main__':
    arr = [1, 2, 3]
    print(solution(arr))