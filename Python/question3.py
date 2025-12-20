output_file = "output.txt"

user_input = input("Enter text to write to file: ")

try:
    with open(output_file, 'w') as file:
        file.write(user_input)
    print(f"Successfully wrote to {output_file}")
except PermissionError:
    print(f"Permission denied: Cannot write to {output_file}")
except Exception as e:
    print(f"An error occurred: {e}")
