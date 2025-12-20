import openpyxl

# Create attendance workbook
wb = openpyxl.Workbook()
ws = wb.active
ws.title = "Sheet1"

# Add headers
ws.append(['RollNo', 'Name', 'ClassesHeld', 'ClassesAttended'])

# Add sample data
data = [
    [101, 'Aarav Kumar', 100, 92],
    [102, 'Priya Sharma', 100, 68],
    [103, 'Rahul Verma', 100, 85],
    [104, 'Ananya Singh', 100, 72],
    [105, 'Rohan Patel', 100, 95],
    [106, 'Sneha Reddy', 100, 58],
    [107, 'Vikram Joshi', 100, 78],
    [108, 'Kavya Nair', 100, 88]
]

for row in data:
    ws.append(row)

wb.save('attendance.xlsx')
print("Input file attendance.xlsx created!")
