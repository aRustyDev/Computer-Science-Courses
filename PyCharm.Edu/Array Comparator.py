def compareArr(arr1, arr2):
    i = 0
    score = 0
    for ans in arr1:
        if ans == arr2[i]:
            score += 4
        elif arr2[i] == "":
            return score
        else:
            score -= 1
        i += 1
    return score
