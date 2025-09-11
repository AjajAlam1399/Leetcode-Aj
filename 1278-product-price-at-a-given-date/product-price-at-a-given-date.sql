# Write your MySQL query statement below
SELECT product_id ,
COALESCE(
    (SELECT new_price FROM PRODUCTS P2 WHERE P1.product_id=p2.product_id AND 
    P2.change_date<='2019-08-16' ORDER BY p2.change_date DESC Limit 1),10
) as price
FROM (SELECT DISTINCT(product_id )FROM Products) P1