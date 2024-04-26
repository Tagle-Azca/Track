def roman():
    roman_numerals = ['I', 'V', 'X', 'L', 'C', 'D', 'M']
    nums = [1, 5, 10, 50, 100, 500, 1000]

    roman_dict = dict(zip(roman_numerals, nums))

    print(roman_numerals)
    print(nums)  # print


roman()
