-- ========================================
-- Lab 10: Exam Database Queries (Mark_Dangal_Exam)
-- ========================================

USE Mark_Dangal_Exam;

-- Insert additional tuples if needed (ensuring exams and results exist for the queries)
-- Already inserted in Lab 9:
-- Exam: 101-English, 102-DBMS, 103-Math, 104-Science, 105-Nepali
-- Result: 201-101, 202-102, 203-103, 204-104, 205-105

-- ========================================
-- Q1: Retrieve all information about results for an exam held on June 27, 2076, at 12:30, where marks > 50
SELECT R.*
FROM Exam E
INNER JOIN Result R 
ON E.Examno = R.Examno
WHERE E.Date_Time = '2076-06-27 12:30' 
AND R.Marks > 50;
-- Explanation: 
-- 1. Inner join ensures only matching Exam-Result pairs.
-- 2. Filters by exact Date_Time and Marks > 50.
-- 3. Returns only the Result columns for exams meeting the criteria.

-- Q2: Retrieve marks obtained by students in the 'English' exam held on June 21, 2076 at 12:15
SELECT R.Marks
FROM Exam E
INNER JOIN Result R
ON E.Examno = R.Examno
WHERE E.Subject = 'English'
AND E.Date_Time = '2076-06-21 12:15';
-- Explanation: 
-- Filters by Subject and exact Date_Time, joins Exam-Result to get Marks.

-- Q3: Retrieve marks obtained by student with ID 201 in the 'English' subject
SELECT R.Marks
FROM Exam E
INNER JOIN Result R
ON E.Examno = R.Examno
WHERE R.Sid = 201
AND E.Subject = 'English';
-- Explanation:
-- Joins Exam-Result and filters by student ID and subject to get specific marks.

-- Q4: Retrieve dates and times of exams for the 'DBMS' subject
SELECT E.Date_Time
FROM Exam E
INNER JOIN Result R
ON E.Examno = R.Examno
WHERE E.Subject = 'DBMS';
-- Explanation:
-- Returns Date_Time of all exams with Subject = 'DBMS'. 
-- Join ensures only exams with results are considered.

-- Q5: Retrieve subjects and marks for student with ID 204
SELECT E.Subject, R.Marks
FROM Exam E
INNER JOIN Result R
ON E.Examno = R.Examno
WHERE R.Sid = 204;
-- Explanation:
-- Returns all subjects and marks for a particular student (Sid=204). 
-- Uses INNER JOIN to match exams and their results.
