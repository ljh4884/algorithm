def solution(skill, skill_trees):
    answer = 0

    for s in skill_trees:
        count = 0
        check = True
        for seg in s:
            if seg in skill:
                if seg != skill[count]:
                    check = False
                else:
                    count += 1
        if check:
            answer += 1
    return answer