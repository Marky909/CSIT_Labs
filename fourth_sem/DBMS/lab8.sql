-- ========================================
-- Lab 8: Product Database Views and Queries (Mark_Dangal_Product)
-- ========================================

USE Mark_Dangal_Product;

-- Q1: Create a view to retrieve supplier names and corresponding item names
CREATE VIEW Supplier_Item_Info AS
SELECT S.Name AS Supplier_Name, I.Name AS Item_Name
FROM Supplier S
JOIN Supplies SP ON S.Panno = SP.Panno
JOIN Items I ON SP.ItemID = I.ItemID
JOIN Payment P ON I.ItemID = P.ItemID;
-- Explanation: JOINs connect Supplier → Supplies → Items → Payment.
-- View provides easy access to supplier-item relationships.

-- Q2: Create a view to show the relationship between item names and their corresponding payment amounts
CREATE VIEW Item_Payment_Info AS
SELECT I.Name AS Item_Name, P.Amount AS Payment
FROM Items I
JOIN Payment P ON I.ItemID = P.ItemID
JOIN Supplies SP ON I.ItemID = SP.ItemID
JOIN Supplier S ON SP.Panno = S.Panno;
-- Explanation: Provides item name and payment amount for quick reporting.

-- Q3: Create a view to calculate the total payment amount for each supplier
CREATE VIEW Supplier_Total_Payment AS
SELECT S.Name AS Supplier_Name, SUM(P.Amount) AS Total_Payment
FROM Supplier S
JOIN Supplies SP ON S.Panno = SP.Panno
JOIN Items I ON SP.ItemID = I.ItemID
JOIN Payment P ON I.ItemID = P.ItemID
GROUP BY S.Name;
-- Explanation: Aggregates payment amount per supplier for financial summary.

-- Q4: Query to retrieve all records from Supplier_Item_Info view
SELECT * FROM Supplier_Item_Info;

-- Q5: Query to retrieve all records from Item_Payment_Info view
SELECT * FROM Item_Payment_Info;

-- Q6: Query to retrieve all records from Supplier_Total_Payment view
SELECT * FROM Supplier_Total_Payment;
