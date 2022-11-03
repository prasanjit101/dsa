
# string hashing
def string_hash(s):
    h = 0
    g = 31
    for c in s:
        h = h*g + ord(c)
    return h

# kmp algorithm for pattern searching


def kmp_search(text, pattern):
    n = len(text)
    m = len(pattern)
    if m == 0:
        return 0
    if n == 0:
        return -1
    if n < m:
        return -1

    # build the lps array
    lps = [0]*m
    i = 1
    j = 0
    while i < m:
        if pattern[i] == pattern[j]:
            j += 1
            lps[i] = j
            i += 1
        else:
            if j != 0:
                j = lps[j-1]
            else:
                lps[i] = 0
                i += 1

    # search for pattern
    i = 0
    j = 0
    while i < n:
        if text[i] == pattern[j]:
            i += 1
            j += 1
        if j == m:
            print("Pattern found at index " + str(i-j))
            j = lps[j-1]
        elif i < n and text[i] != pattern[j]:
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
