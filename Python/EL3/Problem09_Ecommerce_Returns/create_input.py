import openpyxl

# Create returns workbook
wb = openpyxl.Workbook()
ws = wb.active

# Add headers
ws.append(['OrderID', 'CustomerName', 'RefundMode', 'Amount'])

# Add sample data with valid and invalid entries
data = [
    ['ORD001', 'Amit Gupta', 'UPI', 1500],
    ['ORD002', 'Neha Kapoor', 'CARD', 2500],
    ['ORD003', 'Suresh Kumar', 'CASH', 800],  # Invalid mode
    ['ORD004', 'Divya Nair', 'WALLET', 1200],
    ['ORD005', 'Rajesh Singh', 'UPI', -500],  # Invalid amount
    ['ORD006', 'Pooja Reddy', 'NETBANKING', 3000],  # Invalid mode
    ['ORD007', 'Karan Mehta', 'CARD', 0],  # Invalid amount
    ['ORD008', 'Sanya Joshi', 'UPI', 1800]
]

for row in data:
    ws.append(row)

wb.save('returns.xlsx')
print("Input file returns.xlsx created!")
