def sum_of_even_fibonacci(limit):
    a, b = 1, 2
    total_sum = 0
    
    while a <= limit:
        if a%2 == 0:
            total_sum += a
        a, b = b, a+b

    return total_sum

print(sum_of_even_fibonacci(4000000))