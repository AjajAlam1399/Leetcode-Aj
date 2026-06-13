# Write your MySQL query statement below
SELECT ids as id,count(ids) as num from (SELECT Q1.requester_id as ids from RequestAccepted Q1
UNION ALL
SELECT Q2.accepter_id as ids from RequestAccepted Q2) Q3 group by ids order by num desc limit 1;