Select ROUND((D4.imidateOrderCount/D5.totalCount)*100,2) as immediate_percentage FROM (SELECT Count(*) as 'imidateOrderCount' FROM (SELECT D1.customer_id,
       (SELECT D2.order_date
        FROM Delivery D2
        WHERE D2.customer_id = D1.customer_id
        ORDER BY D2.order_date
        LIMIT 1) AS first_order_date,
       (SELECT D2.customer_pref_delivery_date
        FROM Delivery D2
        WHERE D2.customer_id = D1.customer_id
        ORDER BY D2.order_date
        LIMIT 1) AS first_pref_delivery_date
FROM (SELECT DISTINCT customer_id FROM Delivery) D1) D3 WHERE D3.first_order_date=D3.first_pref_delivery_date) d4
CROSS JOIN
(SELECT count(distinct(customer_id)) as totalCount FROM Delivery) D5;
