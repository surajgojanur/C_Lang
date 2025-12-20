valid_marks = []

try:
    with open("marks.txt", 'r') as file:
        for line in file:
            try:
                valid_marks.append(int(line.strip()))
            except ValueError:
                continue
    
    if valid_marks:
        total = sum(valid_marks)
        print(f"Total: {total}")
        print(f"Average: {total / len(valid_marks):.2f}")
    else:
        print("No valid marks found")
        
except FileNotFoundError:
    print("File not found")
