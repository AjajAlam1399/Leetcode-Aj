# Write your MySQL query statement below

WITH Q AS (SELECT customer_id,count(customer_id) as total_orders, SUM(
    CASE 
    WHEN order_rating is not null 
    THEN 1
    END
) as total_rated_orders , SUM(
    CASE 
    WHEN time(order_timestamp) BETWEEN CAST('11:00:00' AS TIME) AND CAST('14:00:00' AS TIME)
    THEN 1
    WHEN time(order_timestamp) BETWEEN CAST('18:00:00' AS TIME) AND CAST('21:00:00' AS TIME)
    THEN 1
    END
) as total_order_in_peak_hour , AVG(
    CASE 
    WHEN order_rating is not null 
    THEN order_rating
    END
) as avg_rating FROM restaurant_orders group by customer_id 
having count(customer_id)>=3)

SELECT customer_id , total_orders , ROUND((total_order_in_peak_hour/total_orders)*100) as peak_hour_percentage , ROUND(avg_rating,2) as average_rating FROM Q where avg_rating>=4 AND (total_order_in_peak_hour/total_orders)*100>=60 AND
(total_rated_orders/total_orders)*100>=50 ORDER BY average_rating DESC , customer_id DESC