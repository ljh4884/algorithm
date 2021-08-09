def solution(s):
    answer = ''

    check = 1
    for i in range(len(s)):
        if check == 1:
            check = 0
            answer += s[i].upper()
        else:
            answer += s[i].lower()
        if s[i] == ' ':
            check = 1

    return answer


