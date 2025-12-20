#!/usr/bin/env python3
"""
EL3 Lab Assignment - Automated Verification Script
Runs all 10 problems and generates a detailed test report
"""

import os
import subprocess
import sys

def run_command(cmd, cwd):
    """Run a command and return success status"""
    try:
        result = subprocess.run(
            cmd,
            cwd=cwd,
            shell=True,
            capture_output=True,
            text=True,
            timeout=10
        )
        return result.returncode == 0, result.stdout, result.stderr
    except Exception as e:
        return False, "", str(e)

def test_problem(problem_num, name, folder, has_create_input, expected_outputs):
    """Test a single problem"""
    print(f"\n{'='*70}")
    print(f"Testing Problem {problem_num}: {name}")
    print(f"{'='*70}")
    
    base_path = os.path.join("EL3", folder)
    
    # Run create_input.py if needed
    if has_create_input:
        print("→ Creating input file...")
        success, stdout, stderr = run_command("python create_input.py", base_path)
        if success:
            print("  ✓ Input file created")
        else:
            print(f"  ✗ Failed to create input: {stderr}")
            return False
    
    # Run solution.py
    print("→ Running solution...")
    success, stdout, stderr = run_command("python solution.py", base_path)
    if success:
        print("  ✓ Solution executed successfully")
    else:
        print(f"  ✗ Solution failed: {stderr}")
        return False
    
    # Check expected outputs
    print("→ Verifying outputs...")
    all_exist = True
    for output_file in expected_outputs:
        output_path = os.path.join(base_path, output_file)
        if os.path.exists(output_path):
            size = os.path.getsize(output_path)
            print(f"  ✓ {output_file} ({size} bytes)")
        else:
            print(f"  ✗ {output_file} NOT FOUND")
            all_exist = False
    
    return all_exist

def main():
    print("╔════════════════════════════════════════════════════════════════════╗")
    print("║        EL3 Lab Assignment - Comprehensive Verification            ║")
    print("╚════════════════════════════════════════════════════════════════════╝")
    
    problems = [
        (1, "Student Marks Processing", "Problem01_Student_Marks", 
         False, ["student_summary.csv"]),
        
        (2, "Sales Report Generation", "Problem02_Sales_Report", 
         False, ["region_sales.csv"]),
        
        (3, "Attendance Analysis", "Problem03_Attendance_Analysis", 
         True, ["attendance.xlsx", "attendance_report.xlsx"]),
        
        (4, "Employee Salary Update", "Problem04_Employee_Salary", 
         True, ["emp_data.xlsx", "emp_salary.xlsx"]),
        
        (5, "Inventory Check", "Problem05_Inventory_Check", 
         False, ["reorder_list.csv"]),
        
        (6, "Exam Result Merge", "Problem06_Exam_Result_Merge", 
         False, ["final_result.csv"]),
        
        (7, "Monthly Expense Tracker", "Problem07_Expense_Tracker", 
         True, ["expenses.xlsx", "monthly_summary.xlsx"]),
        
        (8, "Bus Pass Requests", "Problem08_Bus_Pass", 
         False, ["bus_pass_fare_list.csv", "bus_pass_status.xlsx"]),
        
        (9, "E-Commerce Returns Validation", "Problem09_Ecommerce_Returns", 
         True, ["returns.xlsx", "returns_clean.csv", "returns_error_log.xlsx"]),
        
        (10, "Electricity Bill Calculator", "Problem10_Electricity_Bill", 
         False, ["bills.xlsx", "billing_errors.csv"])
    ]
    
    results = []
    for problem in problems:
        result = test_problem(*problem)
        results.append((problem[0], problem[1], result))
    
    # Print summary
    print(f"\n{'='*70}")
    print("SUMMARY")
    print(f"{'='*70}")
    
    passed = sum(1 for _, _, r in results if r)
    total = len(results)
    
    for num, name, result in results:
        status = "✓ PASS" if result else "✗ FAIL"
        print(f"Problem {num:2d}: {status} - {name}")
    
    print(f"\n{'-'*70}")
    print(f"Total: {passed}/{total} problems passed")
    print(f"{'='*70}\n")
    
    return 0 if passed == total else 1

if __name__ == "__main__":
    sys.exit(main())
