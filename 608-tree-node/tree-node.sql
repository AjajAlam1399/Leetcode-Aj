# Write your MySQL query statement below
SELECT Q1.id , case 
    when p_id is null then 'Root'
    when NOT EXISTS (SELECT 1  from Tree Q2 where Q1.id=Q2.p_id) then 'Leaf'
    else 'Inner'
 end as type FROM Tree Q1;