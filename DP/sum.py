def sum1(n):
    """
    sum of n numbers - iteration 
    n - unsigned
    """
    result = 0
    for i in range(0,n+1):
        result = result + i
    return result


def sum2(n):
    """
    sum of n numbers - recursion 
    n - unsigned
    """
    if n == 0:
        return 0
    
    if n == 1:
        return 1
    else:
        return n + sum2(n-1)
        

def sum3(n):
    """
    sum of n numbers - expression 
    n - unsigned
    """
    m = n+1
    return (m*(m-1))/2


print(sum1(3))
print(sum2(3))
print(sum3(3))

print(sum1(5))
print(sum2(5))
print(sum3(5))

print(sum1(100))
print(sum2(100))
print(sum3(100))
