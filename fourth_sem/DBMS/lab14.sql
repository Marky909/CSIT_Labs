-- Lab 14 Updates
-- ========================================
USE Mark_Dangall_Exam;
-- Q1: Update students with highest percentage to "master" level

SET SQL_SAFE_UPDATES = 0;

UPDATE Student
SET Level = 'Master'
WHERE Stuid IN (
    SELECT Stuid
    FROM Result
    WHERE Percentage IN (SELECT MAX(Percentage) FROM Result)
);

-- Q2: Delete results with lowest percentage
DELETE FROM Result
WHERE Stuid IN (
    SELECT t.Stuid
    FROM (
        SELECT Stuid
        FROM Result
        WHERE Percentage = (SELECT MIN(Percentage) FROM Result)
    ) AS t
);

-- Q3: Update percentage with 5% increase in "First" division
UPDATE Result
SET Percentage = Percentage + (Percentage * 0.05)
WHERE Divison = 1;

-- Q4: Update email address for a specific student (assuming email column exists)
-- Note: We need to first add the email column since it's not defined
ALTER TABLE Student ADD Email VARCHAR(50);

UPDATE Student
SET Email = 'ramthapa@gmail.com'
WHERE Email = 'ram@gmail.com';

-- Q5: Update student level based on division (excluding 'Fail')
UPDATE Student
SET Level = 'Bachelor'
WHERE Stuid IN (
    SELECT Stuid
    FROM Result
    WHERE Divison NOT IN (0)
);





SELECT * FROM student;
SELECT * FROM result;