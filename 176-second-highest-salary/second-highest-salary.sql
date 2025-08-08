# Write your MySQL query statement below
SELECT IFNULL (
    (SELECT salary from Employee
group by salary 
order by salary desc 
limit 1,1),NULL
)as SecondHighestSalary;