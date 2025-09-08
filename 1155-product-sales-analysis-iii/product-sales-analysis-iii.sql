# Write your MySQL query statement below
SELECT S1.product_id,S1.year as first_year,S1.quantity ,S1.price FROM SALES S1 ,(SELECT product_id,min(year) as 'year'
FROM SALES
GROUP BY product_id) S2 WHERE S1.product_id=S2.product_id AND S1.year=S2.year;