def prime_factors(n):
    m = 2
    factors = []

    while n > 1:
        while n % m == 0:
            n /= m
            factors.append(m)
        m += 1

        if m**2 > n:
            if n != 1:
                factors.append(n)
            break
    
    return factors

print("Enter you number: ")
num = int(input())
print(prime_factors(num))