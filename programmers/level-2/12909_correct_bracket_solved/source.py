def solution(s):
    answer = True

    stack = []

    for seg in s:
        if seg == '(':
            stack.append(seg)
        else:
            if len(stack) == 0:
                return False
            stack.pop()
    if len(stack) != 0:
        return False




    return True