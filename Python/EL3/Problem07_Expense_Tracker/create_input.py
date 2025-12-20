import openpyxl

# Create expenses workbook
wb = openpyxl.Workbook()
ws = wb.active

# Add headers
ws.append(['Date', 'Category', 'Amount'])

# Add sample data
data = [
    ['2024-01-05', 'Food', 500],
    ['2024-01-08', 'Transport', 300],
    ['2024-01-12', 'Food', 450],
    ['2024-01-15', 'Entertainment', 800],
    ['2024-01-18', 'Transport', 250],
    ['2024-01-20', 'Food', 600],
    ['2024-01-22', 'Bills', 1500],
    ['2024-01-25', 'Entertainment', 700],
    ['2024-01-28', 'Transport', 350],
    ['2024-01-30', 'Bills', 2000]
]

for row in data:
    ws.append(row)

wb.save('expenses.xlsx')
print("Input file expenses.xlsx created!")
