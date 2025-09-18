# Write your MySQL query statement below


SELECT DATE_FORMAT(trans_date, '%Y-%m') as 'month',country , count(trans_date) as trans_count,COALESCE(SUM(
    CASE WHEN state="approved" THEN 1 END
),0) as approved_count,
sum(amount) as trans_total_amount,COALESCE(SUM(CASE WHEN state="approved" THEN amount END),0 )as approved_total_amount FROM Transactions GROUP BY EXTRACT(YEAR_MONTH FROM trans_date),country;