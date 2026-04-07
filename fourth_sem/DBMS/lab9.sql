-- ========================================
-- Lab 9: Exam Database JOIN Operations (Mark_Dangal_Exam)
-- ========================================

-- Use database
CREATE DATABASE Mark_Dangal_Exam;
USE Mark_Dangal_Exam;

-- Create Exam table
CREATE TABLE Exam
(
    Examno INT PRIMARY KEY,
    Subject VARCHAR(30),
    Date_Time DATETIME,
    Duration INT
);

-- Create Result table
CREATE TABLE Result
(
    Sid INT PRIMARY KEY,
    Examno INT ,
    FOREIGN KEY (Examno) REFERENCES Exam(Examno),
    Marks INT
);

-- Insert 5 tuples into Exam table
INSERT INTO Exam VALUES
(101,'English','2076-06-21 12:15',3),
(102,'DBMS','2076-06-22 10:00',2),
(103,'Math','2076-06-23 09:30',2),
(104,'Science','2076-06-24 11:00',3),
(105,'Nepali','2076-06-25 12:00',1);

-- Insert 5 tuples into Result table
INSERT INTO Result VALUES
(201,101,80),
(202,102,75),
(203,103,60),
(204,104,90),
(205,105,50);

SELECT * FROM Exam;
SELECT  * FROM Result;

-- ========================================
-- Q1: Simple Join
-- Retrieve all exam-result pairs using old-style join
SELECT *
FROM Exam E, Result R
WHERE E.Examno = R.Examno;
-- Explanation: Returns all rows where Examno matches between Exam and Result. Old-style join.

-- Q2: Inner Join
SELECT *
FROM Exam E
INNER JOIN Result R ON E.Examno = R.Examno;
-- Explanation: Returns only matching records between Exam and Result. Preferred modern syntax.

-- Q3: Left Outer Join
SELECT *
FROM Exam E
LEFT JOIN Result R ON E.Examno = R.Examno;
-- Explanation: Returns all exams even if they have no result. Marks are NULL if no result exists.

-- Q4: Right Outer Join
SELECT *
FROM Exam E
RIGHT JOIN Result R ON E.Examno = R.Examno;
-- Explanation: Returns all results even if there is no matching exam. Exam fields are NULL if missing.

-- Q5: Full Outer Join
SELECT *
FROM Exam E
FULL OUTER JOIN Result R ON E.Examno = R.Examno;
-- Since MYSQL doesnt support FULL OUTER JOIN so using follwing operation to achive the same feet 
SELECT *
FROM Exam E
LEFT JOIN Result R ON E.Examno = R.Examno

UNION

SELECT *
FROM Exam E
RIGHT JOIN Result R ON E.Examno = R.Examno;

-- Explanation: Combines left and right joins. Shows all exams and all results, unmatched rows have NULL.
