def power(a,b):
    """
    Computes a to the power of b using recursion
    """
    if b == 0:
        return 1
    if b == 1:
        return a
    return a * power(a,b-1)


assert(power(2,3) == 8)
assert(power(2,0) == 1)
assert(power(2,1) == 2)
