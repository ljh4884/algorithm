from collections import defaultdict


def solution(n, edge):
    answer = 0
    INF = 20002

    load = {i: [] for i in range(n+1)}

    for (start, end) in edge:
        load[start].append(end)
        load[end].append(start)

    ans_dict = defaultdict(lambda: 0)
    visit = [0 for _ in range(n+1)]

    queue = [(1, 0)]

    while len(queue) != 0:
        cur_node, count = queue[0]
        del queue[0]
        if visit[cur_node] == 1:
            continue
        ans_dict[count] += 1
        visit[cur_node] = 1

        for next_node in load[cur_node]:
            if visit[next_node] == 0:
                queue.append((next_node, count+1))
    answer = sorted(ans_dict.items(), reverse=True)[0][1]

    return answer


if __name__ == "__main__":
    n = 6
    edge = [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]
    print(solution(n, edge))