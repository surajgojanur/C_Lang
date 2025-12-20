import csv
import openpyxl

# Read bus pass requests
with open('bus_pass_requests.csv', 'r') as infile:
    reader = csv.DictReader(infile)
    requests = list(reader)

# Calculate fare for each request
fare_data = []
status_data = []

for req in requests:
    student_id = req['StudentID']
    name = req['Name']
    distance = float(req['Distance'])
    
    # Calculate fare based on distance
    if distance <= 5:
        fare = 400
    elif distance <= 10:
        fare = 650
    else:
        fare = 900
    
    fare_data.append([student_id, name, distance, fare])
    status_data.append([student_id, name, distance, fare, 'Pending'])

# Create bus_pass_fare_list.csv
with open('bus_pass_fare_list.csv', 'w', newline='') as outfile:
    writer = csv.writer(outfile)
    writer.writerow(['StudentID', 'Name', 'Distance', 'Fare'])
    writer.writerows(fare_data)

# Create bus_pass_status.xlsx
wb = openpyxl.Workbook()
ws = wb.active
ws.append(['StudentID', 'Name', 'Distance', 'Fare', 'Status'])

for row in status_data:
    ws.append(row)

wb.save('bus_pass_status.xlsx')

print("Bus pass files created successfully!")
