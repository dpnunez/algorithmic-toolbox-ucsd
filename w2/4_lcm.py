def lcm(a, b):
    for l in range(1, a * b + 1):
        if l % a == 0 and l % b == 0:
            return l

    assert False

def prime_factors(n):
		factors = dict()
		divisor = 2
		while n >= 2:
				if n % divisor == 0:
						factors[divisor] = factors.get(divisor, 0) + 1
						n = n / divisor
				else:
						divisor += 1
		return factors

def merge_factors(factors_a, factors_b):
	unique_factors = list(set(factors_a.keys()).union(set(factors_b.keys())))

	merged = dict()
	for i in unique_factors:
		merged[i] = max(factors_a.get(i, 0), factors_b.get(i, 0))
	
	return merged


def lcm_fast(a, b) :
	prime_factors_a = prime_factors(a)
	prime_factors_b = prime_factors(b)
	merged = merge_factors(prime_factors_a, prime_factors_b)
	print(merge_factors(prime_factors_a, prime_factors_b))
	multiply = 1
	for i in merged.keys():
		amount = merged.get(i, 0)
		multiply *= pow(i, amount)

	return multiply


if __name__ == '__main__':
    a, b = map(int, input().split())
    print(lcm_fast(a, b))

