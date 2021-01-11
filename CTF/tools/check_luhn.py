def digits_of(n):
    return [int(d) for d in str(n)]

def luhn_checksum(card_number):
    digits = digits_of(card_number)
    odd_digits = digits[-1::-2]
    even_digits = digits[-2::-2]
    checksum = 0
    checksum += sum(odd_digits)
    for d in even_digits:
        checksum += sum(digits_of(d*2))
    return checksum % 10

def is_luhn_valid(card_number):
    return luhn_checksum(card_number) == 0

for i in range(5432100000001234, 5432109999991234, 10000):
    if i % 123457 == 0:
        if is_luhn_valid(i):
            print("CTFlearn{" + str(i) + "}")