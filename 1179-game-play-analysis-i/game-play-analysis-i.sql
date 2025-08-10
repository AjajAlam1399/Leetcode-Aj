# Write your MySQL query statement below
SELECT A1.player_id , A1.event_date as 'first_login' FROM ACTIVITY A1
JOIN 
(SELECT player_id,MIN(event_date) AS DT FROM ACTIVITY 
GROUP BY player_id) A2
ON A1.player_id=A2.player_id and A1.event_date=A2.DT;