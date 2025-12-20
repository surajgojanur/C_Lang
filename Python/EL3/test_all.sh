#!/bin/bash

echo "=========================================="
echo "EL3 Lab Assignment - Setup & Test Script"
echo "=========================================="
echo ""

# Install requirements
echo "Installing required packages..."
pip install -q openpyxl
echo "✓ openpyxl installed"
echo ""

# Test each problem
echo "Testing all problems..."
echo ""

# Problem 1
echo "Testing Problem 1: Student Marks Processing..."
cd Problem01_Student_Marks
python solution.py > /dev/null 2>&1
if [ -f "student_summary.csv" ]; then
    echo "✓ Problem 1 - PASSED"
else
    echo "✗ Problem 1 - FAILED"
fi
cd ..

# Problem 2
echo "Testing Problem 2: Sales Report Generation..."
cd Problem02_Sales_Report
python solution.py > /dev/null 2>&1
if [ -f "region_sales.csv" ]; then
    echo "✓ Problem 2 - PASSED"
else
    echo "✗ Problem 2 - FAILED"
fi
cd ..

# Problem 3
echo "Testing Problem 3: Attendance Analysis..."
cd Problem03_Attendance_Analysis
python create_input.py > /dev/null 2>&1
python solution.py > /dev/null 2>&1
if [ -f "attendance_report.xlsx" ]; then
    echo "✓ Problem 3 - PASSED"
else
    echo "✗ Problem 3 - FAILED"
fi
cd ..

# Problem 4
echo "Testing Problem 4: Employee Salary Update..."
cd Problem04_Employee_Salary
python create_input.py > /dev/null 2>&1
python solution.py > /dev/null 2>&1
if [ -f "emp_salary.xlsx" ]; then
    echo "✓ Problem 4 - PASSED"
else
    echo "✗ Problem 4 - FAILED"
fi
cd ..

# Problem 5
echo "Testing Problem 5: Inventory Check..."
cd Problem05_Inventory_Check
python solution.py > /dev/null 2>&1
if [ -f "reorder_list.csv" ]; then
    echo "✓ Problem 5 - PASSED"
else
    echo "✗ Problem 5 - FAILED"
fi
cd ..

# Problem 6
echo "Testing Problem 6: Exam Result Merge..."
cd Problem06_Exam_Result_Merge
python solution.py > /dev/null 2>&1
if [ -f "final_result.csv" ]; then
    echo "✓ Problem 6 - PASSED"
else
    echo "✗ Problem 6 - FAILED"
fi
cd ..

# Problem 7
echo "Testing Problem 7: Expense Tracker..."
cd Problem07_Expense_Tracker
python create_input.py > /dev/null 2>&1
python solution.py > /dev/null 2>&1
if [ -f "monthly_summary.xlsx" ]; then
    echo "✓ Problem 7 - PASSED"
else
    echo "✗ Problem 7 - FAILED"
fi
cd ..

# Problem 8
echo "Testing Problem 8: Bus Pass Requests..."
cd Problem08_Bus_Pass
python solution.py > /dev/null 2>&1
if [ -f "bus_pass_status.xlsx" ] && [ -f "bus_pass_fare_list.csv" ]; then
    echo "✓ Problem 8 - PASSED"
else
    echo "✗ Problem 8 - FAILED"
fi
cd ..

# Problem 9
echo "Testing Problem 9: E-Commerce Returns..."
cd Problem09_Ecommerce_Returns
python create_input.py > /dev/null 2>&1
python solution.py > /dev/null 2>&1
if [ -f "returns_clean.csv" ] && [ -f "returns_error_log.xlsx" ]; then
    echo "✓ Problem 9 - PASSED"
else
    echo "✗ Problem 9 - FAILED"
fi
cd ..

# Problem 10
echo "Testing Problem 10: Electricity Bill..."
cd Problem10_Electricity_Bill
python solution.py > /dev/null 2>&1
if [ -f "bills.xlsx" ] && [ -f "billing_errors.csv" ]; then
    echo "✓ Problem 10 - PASSED"
else
    echo "✗ Problem 10 - FAILED"
fi
cd ..

echo ""
echo "=========================================="
echo "All tests completed!"
echo "=========================================="
