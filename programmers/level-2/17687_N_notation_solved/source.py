def solution(n, t, m, p):
    p -= 1
    answer = ''
    pre_dict = {}
    for i in range(10):
        pre_dict[i] = str(i)

    pre_dict[10] = 'A'
    pre_dict[11] = 'B'
    pre_dict[12] = 'C'
    pre_dict[13] = 'D'
    pre_dict[14] = 'E'
    pre_dict[15] = 'F'


    count = 0
    total_count = 0
    num = 0
    while True:
        if count == t:
            break

        arr = []
        if num == 0:
            arr = [0]
        cur_num = num
        while True:
            if cur_num == 0:
                break
            arr.append(cur_num % n)
            cur_num = cur_num // n

        arr.reverse()

        for i in range(len(arr)):
            if total_count % m == p:
                if count == t:
                    break
                answer += pre_dict[arr[i]]
                count += 1
            total_count += 1
        num += 1

    return answer


print(solution(16,16,2,1))