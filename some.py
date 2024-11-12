some = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

# Create an array with 128 slots (ASCII range) initialized to -1
ascii_index_map = [-1] * 128

# Fill the array with indices from 'some' based on ASCII values
for index, char in enumerate(some):
    ascii_index_map[ord(char)] = index

for l in ascii_index_map:
    print(l)

# Example usage
# print(ascii_index_map[ord("A")])  # Output: 0
# print(ascii_index_map[ord("z")])  # Output: 51
# print(ascii_index_map[ord("+")])  # Output: 62
# print(ascii_index_map[ord("/")])  # Output: 63
# print(ascii_index_map[ord("?")])  # Output: -1 (since '?' is not in 'some')
