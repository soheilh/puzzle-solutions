def calculate_sum_of_multiples(limit):
    total_sum = 0
    for num in range(limit):
        if num%3 == 0 or num%5 == 0:
            total_sum += num
    return total_sum

print(calculate_sum_of_multiples(1000))