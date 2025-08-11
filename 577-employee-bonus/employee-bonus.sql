# Write your MySQL query statement below
SELECT E.name , B.bonus FROM Employee E
LEFT JOIN Bonus B
ON E.empId=B.empId where B.bonus is NULL OR B.bonus<1000;