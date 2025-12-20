import csv
import openpyxl

# Read meter readings
with open('meter_readings.csv', 'r') as infile:
    reader = csv.DictReader(infile)
    readings = list(reader)

# Lists for valid bills and errors
valid_bills = []
error_bills = []

for reading in readings:
    meter_id = reading['MeterID']
    customer = reading['CustomerName']
    previous = int(reading['PreviousReading'])
    current = int(reading['CurrentReading'])
    
    # Calculate units consumed
    units = current - previous
    
    # Check if units are invalid (negative)
    if units < 0:
        error_bills.append([meter_id, customer, previous, current, 'Invalid: Negative units'])
        continue
    
    # Calculate bill amount based on slab rates
    if units <= 100:
        bill_amount = units * 4
    elif units <= 200:
        bill_amount = (100 * 4) + ((units - 100) * 6)
    else:
        bill_amount = (100 * 4) + (100 * 6) + ((units - 200) * 8)
    
    valid_bills.append([meter_id, customer, previous, current, units, bill_amount])

# Write valid bills to Excel
wb = openpyxl.Workbook()
ws = wb.active
ws.append(['MeterID', 'CustomerName', 'PreviousReading', 'CurrentReading', 'UnitsConsumed', 'BillAmount'])

for bill in valid_bills:
    ws.append(bill)

wb.save('bills.xlsx')

# Write errors to CSV
with open('billing_errors.csv', 'w', newline='') as outfile:
    writer = csv.writer(outfile)
    writer.writerow(['MeterID', 'CustomerName', 'PreviousReading', 'CurrentReading', 'ErrorReason'])
    writer.writerows(error_bills)

print("Billing completed successfully!")
