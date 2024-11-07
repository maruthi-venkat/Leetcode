# Write your MySQL query statement below
SELECT name,bonus FROM (SELECT e.name,b.bonus FROM Employee AS e LEFT JOIN Bonus AS b ON e.empId = b.empId) AS temp WHERE bonus IS NULL OR bonus < 1000