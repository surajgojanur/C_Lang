import csv

# Read inventory data
with open('inventory.csv', 'r') as infile:
    reader = csv.DictReader(infile)
    products = list(reader)

# Create reorder list
with open('reorder_list.csv', 'w', newline='') as outfile:
    writer = csv.writer(outfile)
    writer.writerow(['ProductID', 'ProductName', 'Stock', 'ReorderLevel'])
    
    for product in products:
        stock = int(product['Stock'])
        reorder_level = int(product['ReorderLevel'])
        
        # Add to reorder list if stock is below reorder level
        if stock < reorder_level:
            writer.writerow([product['ProductID'], product['ProductName'], stock, reorder_level])

print("Reorder list created successfully!")
