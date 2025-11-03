# Write your MySQL query statement below

WITH Q AS (SELECT store_id , max(price) as expensivePrice , min(price) as cheapPrice FROM inventory group by store_id HAVING COUNT(DISTINCT(product_name))>=3),
Q1 AS (SELECT I.store_id , I.product_name,I.quantity,I.price FROM inventory I
JOIN Q ON Q.store_id=I.store_id AND Q.expensivePrice=I.price),
Q2 AS (SELECT I.store_id , I.product_name,I.quantity,I.price FROM inventory I
JOIN Q ON Q.store_id=I.store_id AND Q.cheapPrice=I.price),

Q3 AS (SELECT Q1.store_id , S.store_name,S.location ,Q1.product_name as most_exp_product , Q2.product_name as cheapest_product , ROUND(Q2.quantity/Q1.quantity,2) as imbalance_ratio FROM Q1 
JOIN Q2 ON Q1.store_id=Q2.store_id
JOIN stores as S
ON Q1.store_id=S.store_id
WHERE Q1.quantity<Q2.quantity
ORDER BY imbalance_ratio DESC , store_name
)

SELECT * FROM Q3;