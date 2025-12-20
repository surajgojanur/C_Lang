text = input("Enter a string to convert to integer: ")

try:
    number = int(text)
    print(f"Conversion successful! The number is: {number}")
except ValueError:
    print(f"Cannot convert '{text}' to an integer")

print("Program continues executing...")
print("This line shows the program didn't stop")
