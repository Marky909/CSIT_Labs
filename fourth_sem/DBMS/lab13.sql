-- ========================================
-- Lab 13: Office Database (Mark_Dangal_Office)
-- ========================================

-- Use your database
CREATE DATABASE Mark_Dangal_Office;
USE Mark_Dangal_Office;

-- ========================================
-- Create Supervisor Table
-- ========================================
CREATE TABLE Supervisor (
    SSN INT PRIMARY KEY,
    Sname VARCHAR(50),
    Contact BIGINT,
    Email VARCHAR(50)
);

-- Project table
CREATE TABLE Project (
    Projid INT PRIMARY KEY,
    Pname VARCHAR(50),
    Deadline DATE,
    Duration INT,
    Supervisor INT,
    FOREIGN KEY (Supervisor) REFERENCES Supervisor(SSN)
);

-- Employee table
CREATE TABLE Employee (
    Eid INT PRIMARY KEY,
    Ename VARCHAR(50),
    Address VARCHAR(100),
    Department VARCHAR(50),
    ProjectID INT,
    FOREIGN KEY (ProjectID) REFERENCES Project(Projid)
);

-- ========================================
-- Insert Tuples into Supervisor
-- ========================================
INSERT INTO Supervisor(SSN, Sname, Contact, Email)
VALUES
(101,'Rahul',9816700001,'rahul7@gmail.com'),
(102,'Sita',9816700002,'sita7@gmail.com'),
(103,'Hari',9816700003,'hari7@gmail.com'),
(104,'Gita',9816700004,'gita7@gmail.com'),
(105,'Ram',9816700005,'ram7@gmail.com');

-- ========================================
-- Insert Tuples into Project
-- ========================================
INSERT INTO Project(Projid, Pname, Deadline, Supervisor, Duration)
VALUES
(201,'Electricity','2078-06-21',101,3),
(202,'Water Supply','2078-07-15',102,4),
(203,'IT Upgrade','2078-08-01',103,2),
(204,'Security','2078-09-10',104,5),
(205,'Renovation','2078-09-30',105,1);

-- ========================================
-- Insert Tuples into Employee
-- ========================================
INSERT INTO Employee(Eid, Ename, Address, Department, ProjectID)
VALUES
(301,'Shyam','Dang','Security',202),
(302,'Sita','KTM','IT',203),
(303,'Rajan','Pokhara','Maintenance',NULL),  -- Not assigned to any project
(304,'Gita','Lalitpur','HR',201),
(305,'Ram','Bhaktapur','Finance',204);

SELECT * FROM employee;

SELECT * FROM project;

SELECT * FROM supervisor;

-- ========================================
-- Q1: Retrieve the names of employees who are not assigned to any projects
SELECT E.Ename
FROM Employee E
LEFT JOIN Project P ON E.ProjectID = P.Projid
WHERE E.ProjectID IS NULL;
-- Explanation:
-- LEFT JOIN ensures all employees are considered.
-- WHERE ProjectID IS NULL filters employees with no project assigned.

-- ========================================
-- Q2: Retrieve the names of employees working on projects with the maximum duration
SELECT E.Ename, S.Sname AS SupervisorName
FROM Employee E
INNER JOIN Project P ON E.ProjectID = P.Projid
INNER JOIN Supervisor S ON P.Supervisor = S.SSN
WHERE P.Duration = (SELECT MAX(Duration) FROM Project);
-- Explanation:
-- INNER JOIN links Employee → Project → Supervisor.
-- Subquery finds maximum project duration.
-- Filters employees working on those longest-duration projects.

-- ========================================
-- Q3: Retrieve the names of employees who have a supervisor assigned to their project
SELECT DISTINCT E.Ename
FROM Employee E
INNER JOIN Project P ON E.ProjectID = P.Projid
INNER JOIN Supervisor S ON P.Supervisor = S.SSN;
-- Explanation:
-- Employees with assigned projects automatically have a supervisor (via Project.Supervisor).
-- DISTINCT ensures no duplicate names in case of multiple assignments.

-- ========================================
-- Q4: Retrieve information about projects with deadlines within a specific range
SELECT *
FROM Project
WHERE Deadline BETWEEN '2078-06-21' AND '2079-09-11';
-- Explanation:
-- Filters projects with deadlines in the specified date range.
-- SELECT * shows all project details.
