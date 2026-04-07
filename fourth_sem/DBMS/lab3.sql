-- ========================================
-- Lab 3: Bank Database
-- Database: Mark_Dangal_Bank
-- ========================================

-- 1. Create the database
CREATE DATABASE Mark_Dangal_Bank;
USE Mark_Dangal_Bank;

-- 2. Create tables

-- Customer table: stores customer details
CREATE TABLE Customer (
    C_id INT PRIMARY KEY,
    Customer_Name VARCHAR(40),
    Customer_Address VARCHAR(50),
    Customer_Type VARCHAR(20) -- e.g., Regular, Special
);

-- Loan table: stores loan details
CREATE TABLE Loan (
    L_id INT PRIMARY KEY,
    Amount BIGINT,
    Interest_Rate DECIMAL(5,2),
    Year INT,
    Branch VARCHAR(50)
);

-- Borrow table: many-to-many relationship between Customer and Loan
CREATE TABLE Borrow (
    C_id INT,
    L_id INT,
    BorrowedDate DATETIME,
    PRIMARY KEY(C_id, L_id),
    FOREIGN KEY(C_id) REFERENCES Customer(C_id),
    FOREIGN KEY(L_id) REFERENCES Loan(L_id)
);

-- 3. Insert 5 tuples into Customer
INSERT INTO Customer (C_id, Customer_Name, Customer_Address, Customer_Type)
VALUES 
(1, 'Mark', 'Kathmandu', 'Regular'),
(2, 'John', 'Pokhara', 'Special'),
(3, 'Mary', 'Biratnagar', 'Regular'),
(4, 'Anna', 'Lalitpur', 'Special'),
(5, 'Peter', 'Bhaktapur', 'Regular'),
(6, 'Linda', 'Butwal', 'Special');


-- 4. Insert 5 tuples into Loan
INSERT INTO Loan (L_id, Amount, Interest_Rate, Year, Branch)
VALUES
(101, 500000, 7.50, 2025, 'Main Branch'),
(102, 750000, 8.25, 2024, 'City Branch'),
(103, 300000, 6.80, 2025, 'Town Branch'),
(104, 450000, 7.20, 2023, 'Main Branch'),
(105, 900000, 8.50, 2026, 'Regional Branch');


-- 5. Insert 5 tuples into Borrow
INSERT INTO Borrow VALUES (1,101,'2016-07-09');
INSERT INTO Borrow VALUES (2,102,'2016-07-09');
INSERT INTO Borrow VALUES (3,103,'2016-07-10');
INSERT INTO Borrow VALUES (4,104,'2016-07-11');
INSERT INTO Borrow VALUES (5,105,'2016-07-12');


SELECT * FROM customer;
SELECT * FROM Loan ;

SELECT * FROM Borrow;

