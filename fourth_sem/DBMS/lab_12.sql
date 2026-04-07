-- ======================================================
-- Lab 12
-- Exam Database SQL Queries with Explanations
-- ======================================================

-- Create Database
CREATE DATABASE Mark_Dangall_Exam;
USE Mark_Dangall_Exam;

-- ======================================================
-- Create Table: Student
-- ======================================================
CREATE TABLE student(
    stuid INT PRIMARY KEY,
    name VARCHAR(20),
    address VARCHAR(30),
    contact BIGINT,
    age INT,
    level VARCHAR(50)
);

-- ======================================================
-- Create Table: Result
-- ======================================================
CREATE TABLE result(
    examno INT PRIMARY KEY,
    percentage FLOAT,
    division INT,
    stuid INT,
    FOREIGN KEY (stuid) REFERENCES student(stuid)
);

-- ======================================================
-- Insert sample tuples into Student
-- ======================================================
INSERT INTO student (stuid, name, address, contact, age, level) VALUES
(1, 'Ram', 'Kathmandu', 9801234567, 21, 'Bachelor'),
(2, 'Sita', 'Pokhara', 9802345678, 20, 'Bachelor'),
(3, 'Hari', 'Lalitpur', 9803456789, 22, 'Bachelor'),
(4, 'Gita', 'Bhaktapur', 9804567890, 23, 'Bachelor'),
(5, 'Krishna', 'Biratnagar', 9805678901, 21, 'Bachelor');

-- ======================================================
-- Insert sample tuples into Result
-- ======================================================
INSERT INTO result (examno, percentage, division, stuid) VALUES
(101, 78.5, 1, 1),
(102, 82.0, 1, 2),
(103, 65.4, 2, 3),
(104, 59.0, 2, 4),
(105, 91.2, 1, 5);

-- ======================================================
-- View data for verification
-- ======================================================
SELECT * FROM student;
SELECT * FROM result;

-- ======================================================
-- Q1) Retrieve information about students who have no results recorded.
-- Approach: Use NOT EXISTS to filter students who are not linked to any result.
-- ======================================================
SELECT *
FROM student s
WHERE NOT EXISTS (
    SELECT 1
    FROM result r
    WHERE r.stuid = s.stuid
);

-- ======================================================
-- Q2) Retrieve the names of students whose percentage is above the average percentage.
-- Approach: Compare each student's percentage with the overall AVG(percentage).
-- ======================================================
SELECT s.name, r.percentage
FROM student s
JOIN result r ON s.stuid = r.stuid
WHERE r.percentage > (
    SELECT AVG(percentage) FROM result
);

-- ======================================================
-- Q3) Retrieve result information for students who are above 18 years old 
--     AND have a percentage below the average.
-- Approach: Apply both conditions in WHERE clause.
-- ======================================================
SELECT r.*
FROM result r
JOIN student s ON r.stuid = s.stuid
WHERE s.age > 18
  AND r.percentage < (
      SELECT AVG(percentage) FROM result
);

-- ======================================================
-- Q4) Retrieve information about students who have the highest percentage 
--     in their respective division.
-- Approach: Use correlated subquery to compare each student’s percentage 
--           with the maximum percentage of that division.
-- ======================================================
SELECT s.name, s.level, r.divison, r.percentage
FROM student s
JOIN result r ON s.stuid = r.stuid
WHERE r.percentage = (
    SELECT MAX(r2.percentage)
    FROM result r2
    WHERE r2.divison = r.divison
);

