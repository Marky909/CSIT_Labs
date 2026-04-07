-- ========================================
-- Lab 11: Exam Database Analysis Queries (Mark_Dangal_Exam)
-- ========================================

USE Mark_Dangal_Exam;

-- Assuming Exam and Result tables already have 5 tuples from Lab 9:
-- Exam: 101-English, 102-DBMS, 103-Math, 104-Science, 105-Nepali
-- Result: 201-101, 202-102, 203-103, 204-104, 205-105

-- ========================================
-- Q1: Calculate the average marks for each exam
SELECT R.Examno, AVG(R.Marks) AS 'Average Marks'
FROM Result R
GROUP BY R.Examno;
-- Explanation:
-- GROUP BY Examno groups all results per exam.
-- AVG(Marks) calculates average marks for each exam.

-- Q2: Find the maximum duration among all exams
SELECT MAX(E.Duration) AS 'Maximum Duration'
FROM Exam E;
-- Explanation:
-- MAX(Duration) returns the longest exam duration among all exams.

-- Q3: Retrieve the student IDs who appeared in exam number 106
SELECT R.Sid
FROM Result R
WHERE R.Examno = 106;
-- Explanation:
-- Filters Result table for Examno = 106 and returns matching student IDs.
-- Note: If Examno 106 does not exist, this returns empty set.

-- Q4: Find the highest marks obtained among all students
SELECT MAX(R.Marks) AS 'Highest Marks'
FROM Result R;
-- Explanation:
-- MAX(Marks) returns the highest score obtained by any student in all exams.

-- Q5: Retrieve exam numbers where the duration was less than 3 hours and marks > 50
SELECT DISTINCT E.Examno
FROM Exam E
INNER JOIN Result R ON E.Examno = R.Examno
WHERE E.Duration < 3
AND R.Marks > 50;
-- Explanation:
-- INNER JOIN ensures only exams with results are considered.
-- Filters exams with Duration < 3 hours and marks > 50.
-- DISTINCT avoids duplicate exam numbers in case multiple students took the same exam.
