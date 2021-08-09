def solution(a, b):
    answer = 0
    a = sorted(a)
    b = sorted(b, reverse=True)

    for i in range(len(a)):
        answer += a[i] * b[i]

    return answer