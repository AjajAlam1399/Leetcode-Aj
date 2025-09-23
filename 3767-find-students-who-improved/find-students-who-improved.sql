# Write your MySQL query statement below
with X as (
    select *, row_number() over (partition by student_id, subject order by exam_date) as rn,
    count(*) over (partition by student_id, subject) as cnt
    from Scores
),
Y as (
    select student_id, subject,
    max(case when rn = 1 then score end) as first_score,
    max(case when rn = cnt then score end) as latest_score
    from X group by student_id, subject
)
select * from Y where first_score < latest_score