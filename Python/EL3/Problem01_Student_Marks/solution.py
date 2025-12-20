import csv

# Read students.csv and calculate average marks
with open('students.csv', 'r') as infile:
    reader = csv.DictReader(infile)
    students = list(reader)

# Open output file
with open('student_summary.csv', 'w', newline='') as outfile:
    writer = csv.writer(outfile)
    writer.writerow(['RollNo', 'Name', 'AverageMarks', 'Result'])
    
    for student in students:
        # Calculate average of three subjects
        avg = (int(student['Math']) + int(student['Physics']) + int(student['Chemistry'])) / 3
        
        # Determine result
        if avg >= 40:
            result = 'Pass'
        else:
            result = 'Fail'
        
        writer.writerow([student['RollNo'], student['Name'], round(avg, 2), result])

print("Student summary created successfully!")
