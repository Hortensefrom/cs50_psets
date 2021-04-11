import sys
import cs50


def main():
    
    # Open database
    db = cs50.SQL("sqlite:///students.db")
    
    # Ensure the right number of arguments is provided
    if len(sys.argv) != 2:
        print("Error : wrong number of arguments")
        sys.exit(1)
    
    # Get list from database
    list = db.execute(f"SELECT * FROM students WHERE house = '{sys.argv[1]}' ORDER BY last, first")
    
    # Iterate over list and print
    for row in list:
        if row['middle'] is None: 
            print(f"{row['first']} {row['last']}, born {row['birth']}")
        else:
            print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")
        
        
main()