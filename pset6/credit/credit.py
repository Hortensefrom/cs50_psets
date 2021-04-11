from cs50 import get_string
import re


# Main function

def main():
    # Prompt card number from user
    n = get_string("Number:")
    
    # Check for card validity
    if validCard(n):
        
        # Check if any card type matches
        if re.search("^3[4|7]\d+", n) and len(n) == 15:
            print("AMEX")
            return True
        if re.search("^5[1-5]\d+", n) and len(n) == 16:
            print("MASTERCARD")
            return True
        if re.search("^4\d+", n) and (len(n) == 16 or len(n) == 13):
            print("VISA")
            return True
    
    # Print invalid if false
    else:
        print("INVALID")
        return False


# Checks the validity of the card number
def validCard(n):
    
    s = reverse(n)
    checkSumArr = []
    checkSum = 0
    
    if lengthIsEven(n):
        index = 0
    else:
        index = 1
    
    for i in range(round(len(n)/2) - index):
        checkSumArr.append(int(s[i * 2 + 1]) * 2)
        if checkSumArr[i] > 9:
            checkSumArr[i] = str(checkSumArr[i])
            checkSumArr[i] = int(checkSumArr[i][0]) + int(checkSumArr[i][1])
            checkSumArr[i] = int(checkSumArr[i])
        
    for i in checkSumArr:
        checkSum += int(i)
        
    for i in range(round(len(n)/2)):
        checkSum += int(s[i * 2])
        
    if checkSum % 10 == 0:
        return True
        
    return False
    
    
# Reverse card number
def reverse(s):
    return s[::-1]


# Check if length is even
def lengthIsEven(n):
    if len(n) % 2 == 0:
        return True
    return False
    
    
main()
