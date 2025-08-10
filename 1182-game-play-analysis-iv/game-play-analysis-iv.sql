# Write your MySQL query statement below

SELECT ROUND(playerCnt/totalCnt,2) as fraction FROM(Select COUNT(*) as playerCnt ,(SELECT count(DISTINCT player_id) FROM ACTIVITY) as totalCnt FROM (SELECT A1.player_id,A1.event_date FROM ACTIVITY A1
JOIN (SELECT player_id, min(event_date) as event_date FROM ACTIVITY group by player_id ) A2
on A1.player_id=A2.player_id and A1.event_date=A2.event_date
JOIN ACTIVITY A3
on A1.player_id=A3.player_id AND DATEDIFF(A3.event_date,A1.event_date)=1) A4) A5;
