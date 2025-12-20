file_path = "data2.txt"

try:
    f = open(file_path, 'r')
    for each_line in f:
        each_line = each_line.strip()
        try:
            num = int(each_line)
            print(f"Successfully converted: {num}")
        except ValueError:
            print(f"Error: '{each_line}' is not a valid integer")
            continue
    f.close()
except FileNotFoundError:
    print(f"Error: File '{file_path}' does not exist")
