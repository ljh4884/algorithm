def solution(n):
    answer = 0

    for start in range(1, n+1):
        value = 0
        for i in range(start, n+1):
            value += i
            if value == n:
                answer += 1
                break
            if value > n:
                break

    return answer