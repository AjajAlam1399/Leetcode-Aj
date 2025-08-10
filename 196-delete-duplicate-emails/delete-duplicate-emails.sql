# Write your MySQL query statement below
DELETE p2 FROM PERSON p1
JOIN PERSON p2
on p1.email=p2.email and p1.id<p2.id;
