# Write your MySQL query statement below

(SELECT "Fall" as season,P.category,SUM(CASE WHEN EXTRACT(MONTH FROM S.sale_date) in (9,10,11)
THEN S.quantity END) as total_quantity,SUM(CASE WHEN EXTRACT(MONTH FROM S.sale_date) in (9,10,11)
THEN S.quantity*S.price END) as total_revenue FROM sales S
JOIN PRODUCTS P
on P.product_id=S.product_id
GROUP BY P.category ORDER BY total_quantity DESC , total_revenue DESC LIMIT 1)
UNION ALL
(SELECT "Spring" as season,P.category,SUM(CASE WHEN EXTRACT(MONTH FROM S.sale_date) in (3,4,5)
THEN S.quantity END) as total_quantity,SUM(CASE WHEN EXTRACT(MONTH FROM S.sale_date) in (3,4,5)
THEN S.quantity*S.price END) as total_revenue FROM sales S
JOIN PRODUCTS P
on P.product_id=S.product_id
GROUP BY P.category ORDER BY total_quantity DESC , total_revenue DESC LIMIT 1)
UNION ALL
(SELECT "Summer" as season,P.category,SUM(CASE WHEN EXTRACT(MONTH FROM S.sale_date) in (6,7,8)
THEN S.quantity END) as total_quantity,SUM(CASE WHEN EXTRACT(MONTH FROM S.sale_date) in (6,7,8)
THEN S.quantity*S.price END) as total_revenue FROM sales S
JOIN PRODUCTS P
on P.product_id=S.product_id
GROUP BY P.category ORDER BY total_quantity DESC , total_revenue DESC LIMIT 1)
UNION ALL
(SELECT "Winter" as season,P.category,SUM(CASE WHEN EXTRACT(MONTH FROM S.sale_date) in (12,1,2)
THEN S.quantity END) as total_quantity,SUM(CASE WHEN EXTRACT(MONTH FROM S.sale_date) in (12,1,2)
THEN S.quantity*S.price END) as total_revenue FROM sales S
JOIN PRODUCTS P
on P.product_id=S.product_id
GROUP BY P.category ORDER BY total_quantity DESC , total_revenue DESC LIMIT 1)