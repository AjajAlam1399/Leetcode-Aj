# Write your MySQL query statement below
SELECT E1.name FROM Employee E1
JOIN (SELECT managerId FROM Employee GROUP BY managerId having COUNT(id)>=5) E2
on E1.id=E2.managerId;