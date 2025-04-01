def is_palindrome(string):
    str_length = len(string)

    for i in range(0, str_length):
        if(string[i] != string[str_length - i - 1]):
            return False

    return True


string = input("Enter the string: ")

if is_palindrome(string):
    print("The string is a palindrome")

else :
    print("The string is not a palindrome")