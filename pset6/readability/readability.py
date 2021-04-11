from cs50 import get_string


def main():
    s = get_string("Text: ")
    
    # Initializes variables
    # Words initialized at 1 to account for the last word
    countLetters = 0
    countWords = 1
    countSentences = 0
    
    # Iterate over each character in text
    for c in s:
        if c is " ":
            countWords += 1
        elif c.isalpha():
            countLetters += 1
        elif c == "." or c == "!" or c == "?":
            countSentences += 1
    
    L = (float(countLetters) / countWords) * 100
    S = (float(countSentences) / countWords) * 100
    
    # Calculate index
    index = round(0.0588 * L - 0.296 * S - 15.8)
    
    # Find grade
    if index < 1:
        print("Before Grade 1")
        return 0
    if index < 16:
        print(f"Grade {index}")
        return 0
    if index >= 16:
        print("Grade 16+")
        return 0


main()