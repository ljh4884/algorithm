def solution(files):

    name = {}

    for file in files:
        check = False
        num = 0
        head = ""
        for i, seg in enumerate(file):
            if check == False:
                try:
                    temp = int(seg)
                    check = True
                    head = file[: i].lower()
                    num += temp
                except ValueError:
                    continue
            else:
                try:
                    temp = int(seg)
                    num *= 10
                    num += temp

                except ValueError:
                    break

        name[file] = (head, num)


    size = len(files)

    for i in range(size - 1):
        for j in range(size - 1 - i):
            if name[files[j]][0] == name[files[j + 1]][0]:
                if name[files[j]][1] > name[files[j + 1]][1]:
                    temp = files[j]
                    files[j] = files[j+1]
                    files[j+1] = temp
            elif name[files[j]][0] > name[files[j+1]][0]:
                temp = files[j]
                files[j] = files[j + 1]
                files[j + 1] = temp



    return files

