-- ========================================
-- Lab 4: Bank Database Queries (Mark_Dangal_Bank)
-- ========================================

USE Mark_Dangal_Bank;

-- ========================================
-- Queries for Lab 4
-- ========================================

-- Q1: Add a new column 'Branch' to the Loan table
-- Explanation: Stores branch location for each loan
ALTER TABLE Loan
ADD Branch VARCHAR(30);
-- Note: Branch already inserted in Lab 2 tuples, so this is just for structure

-- Q2: Update Branch Information for specific loans
-- Explanation: Sets the branch for each loan using loan IDs
UPDATE Loan
SET Branch = CASE 
    WHEN L_id = 101 THEN 'Kamalpokhari'
    WHEN L_id = 102 THEN 'Hattisaar'
    WHEN L_id = 103 THEN 'Damak'
    WHEN L_id = 104 THEN 'Pokhara'
    WHEN L_id = 105 THEN 'Dharan'
END
WHERE L_id IN (101, 102, 103, 104, 105);

-- Q3: Select all Branches from the Loan table
SELECT Branch FROM Loan;
-- Explanation: Simple SELECT to view all branch names

-- Q4: Retrieve Customer Details Who Borrowed from 'Hattisaar' Branch
SELECT C.C_id, C.Customer_Name, C.Customer_Address, C.Customer_Type, B.BorrowedDate, L.Amount, L.Interest_Rate
FROM Customer C
JOIN Borrow B ON C.C_id = B.C_id
JOIN Loan L ON B.L_id = L.L_id
WHERE L.Branch = 'Hattisaar';
-- Explanation: JOINs used to link Customer → Borrow → Loan to filter by branch

-- Q5: Select Customers with Loans Having Interest Rates Greater Than 2%
SELECT C.Customer_Name, L.Amount, L.Interest_Rate
FROM Customer C
JOIN Borrow B ON C.C_id = B.C_id
JOIN Loan L ON B.L_id = L.L_id
WHERE L.Interest_Rate > 2;
-- Explanation: Filters customers whose borrowed loans have interest rate > 2%

-- Q6: Retrieve Details of Customers Who Borrowed on a Specific Date and Are in Their Fourth Year
SELECT C.C_id, C.Customer_Name, L.L_id, L.Year, B.BorrowedDate
FROM Customer C
JOIN Borrow B ON C.C_id = B.C_id
JOIN Loan L ON B.L_id = L.L_id
WHERE B.BorrowedDate = '2016-07-09' AND L.Year = 4;
-- Explanation: Retrieves customers who borrowed on '2016-07-09' with loan duration/year = 4

-- Q7: Fetch Loan and Customer Details for a Specific Customer ID (C_id = 3)
SELECT C.C_id, C.Customer_Name, L.L_id, L.Amount, L.Interest_Rate, L.Year, L.Branch
FROM Customer C
JOIN Borrow B ON C.C_id = B.C_id
JOIN Loan L ON B.L_id = L.L_id
WHERE C.C_id = 3;
-- Explanation: Retrieves all loan information for customer with ID 3

-- Q8: Select All Loan Details for Loans Borrowed on a Specific Date ('2016-07-09')
SELECT C.C_id, C.Customer_Name, L.L_id, L.Amount, L.Interest_Rate, L.Year, L.Branch, B.BorrowedDate
FROM Customer C
JOIN Borrow B ON C.C_id = B.C_id
JOIN Loan L ON B.L_id = L.L_id
WHERE B.BorrowedDate = '2016-07-09';
-- Explanation: Retrieves all loan info borrowed on a specific date
