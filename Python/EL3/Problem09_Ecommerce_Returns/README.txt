Problem 9: E-Commerce Returns Validation

Input Files:
- returns.xlsx

Output Files:
- returns_clean.csv
- returns_error_log.xlsx

Logic:
Read returns from Excel, validate RefundMode (must be UPI/CARD/WALLET) and Amount (must be > 0), write valid returns to CSV and invalid returns with error reasons to Excel.

Note: Run create_input.py first to generate returns.xlsx
