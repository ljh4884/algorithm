def solution(n):
    a = 0
    b = 1
    if n == 0:
        return 0
    if n == 1:
        return 1
    for i in range(n-1):
        a, b = b, (a+b) % 1234567

    return b