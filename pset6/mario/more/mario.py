from cs50 import get_int

# Main function


def main():
    n = get_height()
    for i in range(n):
        print(" " * (n - i - 1) + "#" * (i + 1) + "  " + "#" * (i + 1))
    
# Prompt the user for an integer between 1 and 8


def get_height():
    n = get_int("Height:")
    while n < 1 or n > 8:
        n = get_int("Height:")
    return n
    
    
# Call the main function
main()