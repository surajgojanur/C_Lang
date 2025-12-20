class InvalidNumberError(Exception): pass

file = "numbers10.txt"
valid = []

try:
    for line in open(file):
        s = line.strip()
        if not s: continue

        if any(c.isalpha() for c in s):
            print(f"Letters found in line: '{s}'")
            continue

        try:
            valid.append(int(s))
        except ValueError:
            pass  # skip non-int numeric values
except FileNotFoundError:
    print("Input file not found")
else:
    print(f"Collected {len(valid)} valid integers: {valid}")
