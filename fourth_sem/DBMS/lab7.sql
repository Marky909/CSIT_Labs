-- ========================================
-- Lab 7: Product Database Queries (Mark_Dangal_Product)
-- ========================================

USE Mark_Dangal_Product;

-- Q1: Update the address of the supplier with Panno=103 to 'Bhaktapur'
UPDATE Supplier
SET Address = 'Bhaktapur'
WHERE Panno = 103;
-- Explanation: Simple UPDATE query filtered by primary key to change the address.

-- Q2: Retrieve all information about suppliers who supply 'Biscuits'
SELECT S.*
FROM Supplier S
JOIN Supplies SP ON S.Panno = SP.Panno
JOIN Items I ON SP.ItemID = I.ItemID
WHERE I.Name = 'Biscuits';
-- Explanation: JOINs connect Supplier → Supplies → Items; filter by item name to get suppliers.

-- Q3: Retrieve names of items and their corresponding payment amounts for supplier 'Pashupati'
SELECT I.Name AS Item_Name, P.Amount AS Payment
FROM Supplier S
JOIN Supplies SP ON S.Panno = SP.Panno
JOIN Items I ON SP.ItemID = I.ItemID
JOIN Payment P ON I.ItemID = P.ItemID
WHERE S.Name = 'Pashupati';
-- Explanation: Multi-table JOIN ensures we only get items supplied by 'Pashupati' with payments.

-- Q4: Retrieve supplier name and contact info for a specific payment (PaymentNo=501, ItemID=305)
-- Using existing example: PaymentNo=302, ItemID=202
SELECT S.Name AS Supplier_Name, C.Contact
FROM Supplier S
JOIN Supplies SP ON S.Panno = SP.Panno
JOIN Items I ON SP.ItemID = I.ItemID
JOIN Payment P ON I.ItemID = P.ItemID
JOIN Contact C ON S.Panno = C.Panno
WHERE P.PaymentNo = 302 AND I.ItemID = 202;
-- Explanation: JOINs fetch supplier info and contact based on a specific payment and item.

-- Q5: Calculate total quantity of each item type for payments between 1000 and 1,000,000
SELECT I.Type, SUM(I.Quantity) AS Total_Quantity
FROM Items I
JOIN Payment P ON I.ItemID = P.ItemID
WHERE P.Amount BETWEEN 1000 AND 1000000
GROUP BY I.Type;
-- Explanation: Aggregates quantity by item type for payments in a specific range.

-- Q6: Retrieve payment amounts for supplier 'Rajeev'
SELECT P.Amount
FROM Supplier S
JOIN Supplies SP ON S.Panno = SP.Panno
JOIN Items I ON SP.ItemID = I.ItemID
JOIN Payment P ON I.ItemID = P.ItemID
WHERE S.Name = 'Rajeev';
-- Explanation: Fetches all payment amounts for items supplied by 'Rajeev'.

-- Q7: Count the number of transactions of each item type for a specific date ('2023-01-11')
SELECT I.Type, COUNT(P.PaymentNo) AS Num_Transactions
FROM Items I
JOIN Payment P ON I.ItemID = P.ItemID
JOIN Supplies SP ON I.ItemID = SP.ItemID
JOIN Supplier S ON SP.Panno = S.Panno
WHERE P.LoggedDate = '2023-01-11'
GROUP BY I.Type;
-- Explanation: Aggregates the number of payments (transactions) for each item type on a given date.
