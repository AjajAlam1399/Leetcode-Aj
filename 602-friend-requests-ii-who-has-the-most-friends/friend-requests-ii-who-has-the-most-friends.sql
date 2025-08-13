# Write your MySQL query statement below
SELECT E.id,COUNT(E.id) as num FROM  (SELECT requester_id as id FROM RequestAccepted
UNION ALL 
SELECT accepter_id as id FROM RequestAccepted) E group by E.id ORDER BY num
DESC limit 1;