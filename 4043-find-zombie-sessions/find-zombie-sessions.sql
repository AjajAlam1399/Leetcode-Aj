# Write your MySQL query statement below

WITH Q as(select session_id,user_id,MIN(event_timestamp) as start_event_date , Max(event_timestamp) as end_event_Date , SUM(
    CASE WHEN event_type = 'scroll'THEN 1 else 0 END 
)as scroll_count , SUM(
    CASE WHEN event_type = 'click'THEN 1 else 0 END 
)as click_count , SUM(
    CASE WHEN event_type = 'purchase'THEN 1 else 0 END
)as purchanse_count from app_events group by session_id,user_id)


SELECT session_id ,user_id , TIMESTAMPDIFF(MINUTE,start_event_Date,end_event_date) as session_duration_minutes , scroll_count from Q 
where TIMESTAMPDIFF(MINUTE,start_event_Date,end_event_date)>30 and scroll_count>=5 and (click_count/scroll_count)<0.20 and purchanse_count=0 order by scroll_count desc , session_id;

