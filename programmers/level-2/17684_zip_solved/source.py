def solution(msg):
    answer = []
    alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    data = {w: i+1 for i, w in enumerate(alpha)}
    count = 27

    start = 0

    size = len(msg)
    end = size
    while True:

        try:
            num = data[msg[start:end]]

            if end == size:
                answer.append(data[msg[start:end]])
                break

            data[msg[start:end+1]] = count
            count += 1

            answer.append(num)
            start = end
            end = size
        except KeyError:
            end -= 1

    return answer


print(solution("TOBEORNOTTOBEORTOBEORNOT"))