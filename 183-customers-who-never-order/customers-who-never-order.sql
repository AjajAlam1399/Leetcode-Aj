# Write your MySQL query statement below

SELECT Customers.name as Customers from Customers
WHERE Customers.id NOT IN 
(SELECT customerId from Orders);