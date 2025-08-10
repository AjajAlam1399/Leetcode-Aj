# Write your MySQL query statement below

SELECT d.name as 'Department',e1.name as 'Employee',e1.salary as Salary FROM Employee e1
JOIN
(SELECT MAX(salary) as sal,departmentId FROM EMPLOYEE
GROUP BY departmentId) e2
ON e1.salary=e2.sal AND e1.departmentId=e2.departmentId
JOIN Department d
on d.id=e2.departmentId;