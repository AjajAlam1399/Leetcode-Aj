# Write your MySQL query statement below

SELECT transaction_date , COALESCE(
    SUM(CASE
    WHEN amount%2!=0 THEN amount
    END),0
) as odd_sum , COALESCE(
    SUM(CASE
    WHEN amount%2=0 THEN amount
    END),0
) as even_sum FROM transactions group by transaction_date ORDER BY transaction_date ;