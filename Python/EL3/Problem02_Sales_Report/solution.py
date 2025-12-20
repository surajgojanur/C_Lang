import csv

# Dictionary to store region-wise total sales
region_sales = {}

# Read daily sales file line by line
with open('daily_sales.csv', 'r') as infile:
    reader = csv.DictReader(infile)
    
    for row in reader:
        region = row['Region']
        sales = int(row['Sales'])
        
        # Add to region total
        if region in region_sales:
            region_sales[region] += sales
        else:
            region_sales[region] = sales

# Write region sales report, excluding regions with total < 50000
with open('region_sales.csv', 'w', newline='') as outfile:
    writer = csv.writer(outfile)
    writer.writerow(['Region', 'TotalSales'])
    
    for region, total in region_sales.items():
        if total >= 50000:
            writer.writerow([region, total])

print("Region sales report created successfully!")
