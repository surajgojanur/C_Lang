in_file = "expenses_input.txt"
clean_file = "expenses_cleaned.txt"
rejected_file = "expenses_rejected.txt"

clean, rejected = [], []

try:
    with open(in_file) as fin:
        for raw in fin:
            line = raw.strip()
            if not line:
                rejected.append("EMPTY\t")
                continue
            parts = [p.strip() for p in line.split(",")]
            if len(parts) != 2 or not parts[0]:
                rejected.append(f"SPLIT_OR_CATEGORY\t{line}")
                continue
            cat, amt = parts
            try:
                val = float(amt)
            except ValueError:
                rejected.append(f"AMOUNT_INVALID\t{line}")
                continue
            if val < 0:
                rejected.append(f"AMOUNT_NEGATIVE\t{line}")
                continue
            clean.append(f"{cat.lower()}, {val:.2f}")
except FileNotFoundError:
    print("Input file not found")
else:
    try:
        with open(clean_file, "w") as cf:
            cf.write("\n".join(clean))
        with open(rejected_file, "w") as rf:
            rf.write("\n".join(rejected))
        print(f"Cleaned {len(clean)}, Rejected {len(rejected)}")
    except PermissionError:
        print("Permission denied when writing outputs")
