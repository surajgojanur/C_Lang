import csv

# Read theory marks
with open('theory_marks.csv', 'r') as file:
    theory_reader = csv.DictReader(file)
    theory_data = {row['RollNo']: row for row in theory_reader}

# Read lab marks
with open('lab_marks.csv', 'r') as file:
    lab_reader = csv.DictReader(file)
    lab_data = {row['RollNo']: row for row in lab_reader}

# Merge and write final result
with open('final_result.csv', 'w', newline='') as outfile:
    writer = csv.writer(outfile)
    writer.writerow(['RollNo', 'Name', 'TheoryMarks', 'LabMarks', 'TotalMarks', 'Result'])
    
    for roll_no in theory_data:
        name = theory_data[roll_no]['Name']
        theory = int(theory_data[roll_no]['TheoryMarks'])
        lab = int(lab_data[roll_no]['LabMarks'])
        
        # Calculate total marks
        total = theory + lab
        
        # Determine result
        if total >= 40:
            result = 'Pass'
        else:
            result = 'Fail'
        
        writer.writerow([roll_no, name, theory, lab, total, result])

print("Final result file created successfully!")
