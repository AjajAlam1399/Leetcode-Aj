WITH Q AS (
    SELECT MR.*, U.name AS user_name, M.title AS movie_name
    FROM MovieRating MR
    LEFT JOIN Users U ON MR.user_id = U.user_id
    LEFT JOIN Movies M ON M.movie_id = MR.movie_id
)

-- First subquery: user with most ratings
SELECT results FROM (
    SELECT user_name AS results
    FROM Q
    GROUP BY user_id
    ORDER BY COUNT(user_id) DESC, user_name ASC
    LIMIT 1
) AS UserResult

UNION ALL

-- Second subquery: movie with highest avg rating in Feb 2020
SELECT results FROM (
    SELECT movie_name AS results
    FROM Q
    WHERE created_at LIKE '2020-02-%'
    GROUP BY movie_id
    ORDER BY AVG(rating) DESC, movie_name ASC
    LIMIT 1
) AS MovieResult;
