create database Mark_Dangal_store;
use Mark_Dangal_store;



create table Items(
ItemId int primary key,
ItemName varchar(50),
price int,
Quantity int,
MfgDate varchar(50),
ExpDate varchar(50)
);



create table proof(
path varchar(100) primary key
);



create table Household(
ItemId int primary key,
ItemName varchar(50),
price int,
Quantity int,
Mfg_Date varchar(50),
Exp_Date varchar(50)
);


-- Inserting 5 rows in table item

INSERT INTO Items(ItemId,ItemName,price,Quantity,MfgDate,ExpDate) VALUES 
(11,'Mango',50,1,'2022-05-06','2026-05-06'),
(12,'Apple',56,2,'2022-05-07','2027-06-06'),
(13,'Milk',60,3,'2025-06-07','2028-06-06'),
(101,'Meat',70,5,'2025-06-07','2027-06-07'),
(102,'Cotton',4,20,'2025-01-04','2029-06-07');



INSERT INTO Household (ItemID, ItemName, Price, Quantity, Mfg_date, Exp_date) VALUES
(201, 'Detergent', 150.00, 4, '2025-01-05', '2027-01-05'),
(202, 'Toothpaste', 90.00, 6, '2025-01-08', '2026-01-08'),
(203, 'Shampoo', 300.00, 3, '2025-01-02', '2027-01-02'),
(204, 'Soap', 40.00, 15, '2025-01-09', '2026-07-09'),
(205, 'Floor Cleaner', 200.00, 2, '2025-01-01', '2026-01-01');



INSERT INTO proof (path) VALUES
('C:\Users\Mark\Projects\MyFolder');

select * from Items;
select * from Household;
select * from proof;