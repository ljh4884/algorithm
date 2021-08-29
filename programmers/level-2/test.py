def solution(a_list):
    answer = []

    for a in a_list:
        cond = True
        count = 0
        for seg in a:
            if seg == 'a':
                count += 1

        while True:
            if a == 'a' or a == '':
                cond = True
                break

            while a[0] == 'a':
                a = a[1:]
                count -= 1
            while a[len(a) - 1] == 'a':
                a = a[:len(a) - 1]
                count -= 1

            left = 0
            right = 0

            for i in range(len(a)):
                if a[i] == 'a':
                    break
                left += 1

            for i in range(len(a) - 1, -1, -1):
                if a[i] == 'a':
                    break
                right += 1

            if left != right:
                cond = False
                break

            if count != left:
                cond = False
                break

            a = a[left:len(a) - right]
        answer.append(cond)
    return answer

test = solution(["abab","bbaa","bababa","bbbabababbbaa"])

print(test)