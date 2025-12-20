import sys

F = "contacts.txt"
U = "Options:\n  search <term>\n  add <name> <email> <phone>\n"

def search(t):
    try:
        with open(F) as f:
            m = [c.strip() for c in f if t.lower() in c.lower()]
    except FileNotFoundError:
        return print(f"Missing file: '{F}'")
    print("Matches:" if m else "No matches found")
    for x in m: print(x)

def add(n, e, p):
    try:
        with open(F, "a") as f: f.write(f"{n}, {e}, {p}\n")
        print("Contact added")
    except Exception as err:
        print(f"Write error: {err}")

def main(a):
    if len(a) < 2: return print("Invalid option\n" + U)
    c = a[1]
    if c == "search":
        return print("Provide term") if len(a) < 3 else search(a[2])
    if c == "add":
        return print("Provide name email phone") if len(a) < 5 else add(*a[2:5])
    print("Invalid option\n" + U)

if __name__ == "__main__":
    main(sys.argv)
