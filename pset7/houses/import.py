import cs50
import csv
import sys

def main():

    # Ensure proper number of arguments
    if len(sys.argv) != 2:
        print("Error : wrong number of arguments.")

    # Open database
    db = cs50.SQL("sqlite:///students.db")
    
    # Delete students table
    db.execute("DROP TABLE students")
    
    # Create table in database
    db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

    # Open CSV file
    csvFile = sys.argv[1]
    with open(csvFile, "r") as characters:

        # Create DictReader
        reader = csv.DictReader(characters)

        # Iterate over CSV file
        for row in reader:

            name = row["name"].split(" ")
            first = name[0]
            if len(name) == 3:
                middle = name[1]
                last = name[2]
            else:
                middle= None
                last = name[1]
                
            # Insert student
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, middle, last, row["house"], row["birth"])


main()