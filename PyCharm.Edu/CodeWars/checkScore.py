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

# ----------------------------------------------------------------------------------------------------------------------
print("FIRST: ")
print("\t", check_exam(["a", "a", "b", "b"], ["a", "c", "b", "d"]) == 6)
print("SECOND: ")
print("\t", check_exam(["a", "a", "b", "b"], ["a", "c", "b", "d"]))
print("THIRD: ")
print("\t", check_exam(["a", "a", "c", "b"], ["a", "a", "b",  ""]) == 7)
print("FOURTH: ")
print("\t", check_exam(["a", "a", "c", "b"], ["a", "a", "b",  ""]))
