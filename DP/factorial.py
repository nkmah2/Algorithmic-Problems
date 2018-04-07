def factorial(n):
    """
    Computes the factorial using recursion
    """
    if n == 1:
        return 1
    else:
        return n * factorial(n-1)
    
    
    
assert(factorial(5)==120)   
