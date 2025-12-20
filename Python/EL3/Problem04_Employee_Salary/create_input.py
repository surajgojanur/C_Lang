import openpyxl

# Create employee data workbook
wb = openpyxl.Workbook()
ws = wb.active

# Add headers
ws.append(['EmpID', 'Name', 'Department', 'BasicSalary'])

# Add sample data
data = [
    [101, 'Amit Gupta', 'IT', 45000],
    [102, 'Neha Kapoor', 'HR', 38000],
    [103, 'Suresh Kumar', 'Finance', 52000],
    [104, 'Divya Nair', 'IT', 48000],
    [105, 'Rajesh Singh', 'Marketing', 42000],
    [106, 'Pooja Reddy', 'Finance', 55000]
]

for row in data:
    ws.append(row)

wb.save('emp_data.xlsx')
print("Input file emp_data.xlsx created!")
