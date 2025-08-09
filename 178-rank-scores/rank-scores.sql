# Write your MySQL query statement below

SELECT S.score , 
DENSE_RANK() OVER(ORDER BY score DESC) as 'rank'
FROM Scores AS S;