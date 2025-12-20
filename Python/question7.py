in_file = "integers7_input.txt"
out_file = "integers7_output.txt"

try:
    with open(in_file) as fin:
        nums = []
        for s in fin:
            s = s.strip()
            if not s:
                continue
            try:
                nums.append(int(s))
            except ValueError:
                pass
except FileNotFoundError:
    print("Input file not found")
else:
    try:
        with open(out_file, 'w') as fout:
            fout.write("\n".join(str(n) for n in nums))
        print(f"Saved {len(nums)} integers to '{out_file}'")
    except PermissionError:
        print("Permission denied for output file")
