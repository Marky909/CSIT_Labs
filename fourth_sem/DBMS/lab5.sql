-- ========================================
-- Lab 5: Bank Database Queries (Mark_Dangal_Bank)
-- ========================================

USE Mark_Dangal_Bank;

-- Q1: Display all details from the Loan table
SELECT * FROM Loan;
-- Explanation: Simple SELECT to retrieve all loan records. 
-- Useful to verify data and check inserted tuples.

-- Q2: List all customers from the Customer table
SELECT * FROM Customer;
-- Explanation: Shows all customer records, basic table check.

-- Q3: Find the total amount of all loans borrowed by customers
SELECT SUM(L.Amount) AS TotalLoanAmount
FROM Loan L
JOIN Borrow B ON L.L_id = B.L_id;
-- Explanation: JOIN ensures summing only loans that are borrowed.
-- SUM aggregates loan amounts to get total.

-- Q4: Loanid and BorrowedDate for all loans borrowed by customer with C_id=5
SELECT B.L_id, B.BorrowedDate
FROM Borrow B
WHERE B.C_id = 5;
-- Explanation: Filters borrow records for a specific customer ID.

-- Q5: List Custid and Loanid of all loans borrowed in the year 2017
SELECT B.C_id, B.L_id
FROM Borrow B
WHERE YEAR(B.BorrowedDate) = 2017;
-- Explanation: YEAR() function extracts year from BorrowedDate to filter loans.

-- Q6: Count the number of loans with an interest rate of 3%
SELECT COUNT(*) AS LoanCount
FROM Loan L
WHERE L.Interest_Rate = 3;
-- Explanation: Simple COUNT function with WHERE filter.

-- Q7: List all Special type customers who have borrowed loans
SELECT DISTINCT C.C_id, C.Customer_Type
FROM Customer C
JOIN Borrow B ON C.C_id = B.C_id
WHERE C.Customer_Type = 'Special';
-- Explanation: Uses JOIN to only include customers who actually borrowed loans.

-- Q8: Display Custid, Loanid, and Amount of all loans borrowed by Regular type customers
SELECT C.C_id, B.L_id, L.Amount
FROM Customer C
JOIN Borrow B ON C.C_id = B.C_id
JOIN Loan L ON B.L_id = L.L_id
WHERE C.Customer_Type = 'Regular';
-- Explanation: Combines three tables using JOIN to show all relevant info.

-- Q9: Update the interest rate of loan Loanid=105 to 5%
UPDATE Loan
SET Interest_Rate = 5
WHERE L_id = 105;
-- Explanation: Updates specific loan using primary key filter.

-- Q10: Delete all borrow records for customer with C_id=6
DELETE FROM Borrow
WHERE C_id = 6;
-- Explanation: Deletes borrow history for a specific customer.
-- Ensures no dangling loans in Borrow table.
