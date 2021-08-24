
def t2i(time):
    time = time.split(":")
    return int(time[0])*60 + int(time[1])


def trans(music):
    ret = ""
    pos = 0
    while True:
        if pos == len(music):
            break
        if pos+1 == len(music):
            ret += music[pos]
            break
        if music[pos+1] == "#":
            ret += music[pos].lower()
            pos += 2
        else:
            ret += music[pos]
            pos += 1
    return ret


def func(m, music, time):

    size_1 = len(m)
    size_2 = len(music)
    # 끝까지 안가도 알 순 있을꺼 같지만 나중에
    count = 0
    i = 0
    while True:
        if i == time:
            break
        pos_2 = i % size_2

        if count == size_1:
            return True

        if music[pos_2] == m[count]:
            count += 1
        else:
            i -= count
            count = 0
        i += 1
    if count == size_1:
        return True
    return False


def solution(m, musicinfos):
    answer = ''
    time = 0
    m = trans(m)
    for info in musicinfos:
        info = info.split(",")
        start = t2i(info[0])
        end = t2i(info[1])
        name = info[2]
        music = trans(info[3])

        if (end - start) <= time:
            continue
        else:
            if func(m, music, end-start):
                time = end-start
                answer = name
    if answer == "":
        return "(None)"
    return answer

