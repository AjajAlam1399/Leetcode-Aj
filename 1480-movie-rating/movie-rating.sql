# Write your MySQL query statement below
WITH Q AS (SELECT MR.*,U.name as user_name, M.title as movie_name FROM MovieRating MR
LEFT JOIN 
Users U
ON MR.user_id=U.user_id
LEFT JOIN Movies M
ON M.movie_id=MR.movie_id)

SELECT user_name as 'results' From (SELECT user_name ,count(user_id) as ratingCnt from Q group by user_id ORDER BY ratingCnt DESC, user_name ASC limit 1) Q1
UNION ALL
SELECT movie_name as 'results' FROM (SELECT movie_name,AVG(rating) as avg_rating FROM Q WHERE created_at like '2020-02-%'  group by movie_id  ORDER BY avg_rating DESC , movie_name asc Limit 1) Q2;