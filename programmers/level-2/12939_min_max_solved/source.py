def solution(s):
    answer = ''
    min_value = 10000000
    max_value = -10000000
    start = 0
    for i in range(len(s)):
        if s[i] == " ":
            min_value = min(min_value, int(s[start: i]))
            max_value = max(max_value, int(s[start: i]))
            start = i+1
    min_value = min(min_value, int(s[start: len(s)]))
    max_value = max(max_value, int(s[start: len(s)]))

    answer = str(min_value) + " " + str(max_value)

    return answer


if __name__ == '__main__':
    print(solution("1 4 5 9"))