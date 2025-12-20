filename = "data.txt"

try:
    with open(filename, 'r') as file:
        for line in file:
            line = line.strip()
            try:
                number = int(line)
                print(f"Converted: {number}")
            except ValueError:
                print(f"Couldn't convert '{line}' to integer, skipping...")
                continue
except FileNotFoundError:
    print(f"File {filename} not found")
