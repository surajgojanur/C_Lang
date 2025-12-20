Problem 10: Electricity Bill Calculator

Input Files:
- meter_readings.csv

Output Files:
- bills.xlsx
- billing_errors.csv

Logic:
Read meter readings from CSV, calculate units consumed (current - previous), validate units (reject if negative), calculate bill using slab rates (first 100: ₹4/unit, next 100: ₹6/unit, above 200: ₹8/unit), write valid bills to Excel and errors to CSV.
