import re
import sys
import csv


def main():
    
    # Verify right number of arguments
    if len(sys.argv) != 3:
        print("Error : wrong number of arguments.")
        sys.exit(1)
    
    # Open CVS file
    database = open(sys.argv[1], "r")
    if not database:
        print(f"Could not open {sys.argv[1]}")
        sys.exit(1)
    d = csv.DictReader(database)
    
    # Open sequence file
    sequence = open(sys.argv[2], "r")
    if not sequence:
        print(f"Could not open {sys.argv[2]}")
        sys.exit(1)
    s = sequence.read()
        
    # Read databse
    dataReader = csv.DictReader(database)
    
    # Create the dictionary to store STR counts
    STR_count = {}
    
    # Count STR repetitions in sequence 
    for STR in dataReader.fieldnames:
        repeat = 0
        n = len(STR)
        for i in range(len(s)):
            count = 0
            while s[i:i+n] == STR:
                count += 1
                i += n
                repeat = max(count, repeat)
        STR_count[STR] = repeat
    del STR_count['name']
    
    # Compare dataBase with STRcounts
    match = "No match"
    # Iterate over each row of the CSV file
    for row in dataReader:
        i = 0
        # Iterate over each key of the STR count dictionary
        for keys in STR_count:
            if STR_count[keys] == int(row[keys]):
                i += 1
            if i == len(STR_count):
                match = row['name']
    
    # Print result
    
    print(match)

    # Close files
    
    database.close()        
    sequence.close()
    
    
main()