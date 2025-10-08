WITH Q AS (SELECT 
    customer_id,
    MIN(transaction_date) AS min_t_date,
    MAX(transaction_date) AS max_t_date,
    SUM(
        CASE
            WHEN transaction_type = 'purchase' THEN 1
            ELSE 0
        END
    ) AS purchase_cnt,
    COUNT(customer_id) AS total_cnt
FROM customer_transactions
GROUP BY customer_id)

SELECT customer_id from Q WHERE purchase_cnt>=3 AND DATEDIFF(max_t_date,min_t_date)>=30 and ((total_cnt-purchase_cnt)*100)/total_cnt<20 
ORDER BY customer_id;
