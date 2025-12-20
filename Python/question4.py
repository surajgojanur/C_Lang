filename = input("Enter filename to create: ")
content = input("Enter content to write: ")

try:
    f = open(filename, 'w')
    f.write(content)
    f.close()
    print(f"File '{filename}' created successfully")
except PermissionError:
    print(f"Error: No permission to create file '{filename}'")
except IOError as e:
    print(f"IO Error: {e}")
