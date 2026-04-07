-- ========================================
-- Lab 5: Product Database
-- Database: Mark_Dangal_Product
-- ========================================

-- 1. Create the database
CREATE DATABASE Mark_Dangal_Product;
USE Mark_Dangal_Product;

-- 2. Create tables

-- Supplier table: stores supplier info
CREATE TABLE Supplier (
    Panno INT PRIMARY KEY,
    Name VARCHAR(30),
    Address VARCHAR(50)
);

-- Contact table: stores supplier contact numbers
CREATE TABLE Contact (
    Panno INT,
    Contact BIGINT,
    PRIMARY KEY(Panno, Contact),
    FOREIGN KEY(Panno) REFERENCES Supplier(Panno)
);

-- Items table: stores items info
CREATE TABLE Items (
    ItemID INT PRIMARY KEY,
    Name VARCHAR(30),
    Price INT,
    Quantity INT,
    Type VARCHAR(30)
);

-- Supplies table: tracks which supplier supplied which item and date
CREATE TABLE Supplies (
    Panno INT,
    ItemID INT,
    SuppliedDate DATETIME,
    PRIMARY KEY(Panno, ItemID),
    FOREIGN KEY(Panno) REFERENCES Supplier(Panno),
    FOREIGN KEY(ItemID) REFERENCES Items(ItemID)
);

-- Payment table: payment records for items
CREATE TABLE Payment (
    ItemID INT,
    PaymentNo INT,
    Amount INT,
    Quantity INT,
    LoggedDate DATETIME,
    PRIMARY KEY(ItemID, PaymentNo),
    FOREIGN KEY(ItemID) REFERENCES Items(ItemID)
);

-- 3. Insert 5 tuples in Supplier
INSERT INTO Supplier VALUES (101,'Surya','Kathmandu');
INSERT INTO Supplier VALUES (102,'Pashupati','Lalitpur');
INSERT INTO Supplier VALUES (103,'Rajeev','Pokhara');
INSERT INTO Supplier VALUES (104,'Hari','Dharan');
INSERT INTO Supplier VALUES (105,'Gita','Bhaktapur');

-- 4. Insert 5 tuples in Contact
INSERT INTO Contact VALUES (101,9823412345);
INSERT INTO Contact VALUES (102,9812345678);
INSERT INTO Contact VALUES (103,9801234567);
INSERT INTO Contact VALUES (104,9845678901);
INSERT INTO Contact VALUES (105,9876543210);

-- 5. Insert 5 tuples in Items
INSERT INTO Items VALUES (201,'Noodles',20,30,'Grocery');
INSERT INTO Items VALUES (202,'Biscuits',50,40,'Grocery');
INSERT INTO Items VALUES (203,'Soap',25,50,'PersonalCare');
INSERT INTO Items VALUES (204,'Milk',40,60,'Dairy');
INSERT INTO Items VALUES (205,'Cheese',100,20,'Dairy');

-- 6. Insert 5 tuples in Supplies
INSERT INTO Supplies VALUES (101,201,'2023-01-01');
INSERT INTO Supplies VALUES (102,202,'2023-01-02');
INSERT INTO Supplies VALUES (103,203,'2023-01-03');
INSERT INTO Supplies VALUES (104,204,'2023-01-04');
INSERT INTO Supplies VALUES (105,205,'2023-01-05');

-- 7. Insert 5 tuples in Payment
INSERT INTO Payment VALUES (201,301,600,30,'2023-01-10');
INSERT INTO Payment VALUES (202,302,2000,40,'2023-01-11');
INSERT INTO Payment VALUES (203,303,1250,50,'2023-01-12');
INSERT INTO Payment VALUES (204,304,2400,60,'2023-01-13');
INSERT INTO Payment VALUES (205,305,2000,20,'2023-01-14');

SELECT * FROM Supplier;
SELECT * FROM Contact;
SELECT * FROM Items;
SELECT * FROM Supplies;
SELECT * FROM Payment;
