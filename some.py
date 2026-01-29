base64_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
base64_url_safe_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_"
base32_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567"
base32_hex_alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUV"
base16_alphabet = "0123456789ABCDEF"

def get_alphabet(some):
    ascii_index_map = [-1] * 256

    for index, char in enumerate(some):
        ascii_index_map[ord(char)] = index

    return ascii_index_map

for l in get_alphabet(base16_alphabet):
    print(l)



# Example usage
# print(ascii_index_map[ord("A")])  # Output: 0
# print(ascii_index_map[ord("z")])  # Output: 51
# print(ascii_index_map[ord("+")])  # Output: 62
# print(ascii_index_map[ord("/")])  # Output: 63
# print(ascii_index_map[ord("?")])  # Output: -1 (since '?' is not in 'some')
