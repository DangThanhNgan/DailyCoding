def longest_consecutive_sequence(L):
    #convert list to set for O(1)
    num_set = set(L)
    max_length = 0

    for num in num_set:
        if num - 1 not in num_set:
            current_num = num
            current_length = 1

            while current_num + 1 in num_set:
                current_num += 1
                current_length += 1

            max_length = max(max_length, current_length)

    return max_length

L = [5, 2, 99, 3, 4, 1, 100]

result = longest_consecutive_sequence(L)

print(result)