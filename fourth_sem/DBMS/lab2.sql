-- Lab 1: Teacher/Teaches/Course Database
create database Mark_Dangal_school;
use Mark_Dangal_school;
-- 1. Create tables
CREATE TABLE Teacher (
    TID INT PRIMARY KEY,
    TName VARCHAR(30),
    Qualification VARCHAR(30)
);

CREATE TABLE Course (
    C_ID INT PRIMARY KEY,
    C_Name VARCHAR(50),
    C_Code VARCHAR(20)
);

CREATE TABLE Teaches (
    TID INT,
    CID INT,
    PRIMARY KEY(TID, CID),
    FOREIGN KEY(TID) REFERENCES Teacher(TID),
    FOREIGN KEY(CID) REFERENCES Course(C_ID)
);

-- 2. Insert 5 tuples into Teacher
INSERT INTO Teacher VALUES(1,'Ram Prasad','PhD');
INSERT INTO Teacher VALUES(2,'Sita Sharma','MSc');
INSERT INTO Teacher VALUES(3,'Hari Koirala','PhD');
INSERT INTO Teacher VALUES(4,'Gita Thapa','BSc');
INSERT INTO Teacher VALUES(5,'Raju Shrestha','MPhil');

-- 3. Insert 5 tuples into Course
INSERT INTO Course VALUES(101,'Database Systems','DB101');
INSERT INTO Course VALUES(102,'Operating Systems','OS102');
INSERT INTO Course VALUES(103,'Computer Networks','CN103');
INSERT INTO Course VALUES(104,'Software Engineering','SE104');
INSERT INTO Course VALUES(105,'Artificial Intelligence','AI105');

-- 4. Insert 5 tuples into Teaches
INSERT INTO Teaches VALUES(1,101);
INSERT INTO Teaches VALUES(1,103);
INSERT INTO Teaches VALUES(2,102);
INSERT INTO Teaches VALUES(3,104);
INSERT INTO Teaches VALUES(4,105);

SELECT * FROM course;
SELECT * FROM teacher ;

SELECT * FROM teaches;

-- 5. Queries

-- Q1: Find names of all teachers who have PhD qualification
SELECT TName
FROM Teacher
WHERE Qualification='PhD';

-- Q2: Find names of all courses taught by Ram Prasad
SELECT c.C_Name
FROM Teacher t
JOIN Teaches te ON t.TID = te.TID
JOIN Course c ON te.CID = c.C_ID
WHERE t.TName='Ram Prasad';

-- Q3: Find the total number of courses taught by Ram Prasad
SELECT COUNT(c.C_ID) AS TotalCourses
FROM Teacher t
JOIN Teaches te ON t.TID = te.TID
JOIN Course c ON te.CID = c.C_ID
WHERE t.TName='Ram Prasad';
