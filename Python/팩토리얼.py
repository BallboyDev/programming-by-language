def calc_factorial(num):
    if num == 0: return 1
    result = 1
    for i in range(1, num+1):
        result = result * i
    return result

num = int(input("숫자를 입력하시오 : "))
rslt = calc_factorial(num)
print(num,"! =", rslt);
