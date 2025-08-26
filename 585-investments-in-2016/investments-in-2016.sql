WITH Q AS (
    SELECT * 
    FROM Insurance I
    WHERE NOT EXISTS (
        SELECT 1 
        FROM Insurance J
        WHERE I.pid != J.pid 
          AND I.lat = J.lat 
          AND I.lon = J.lon
    )
)
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Q
WHERE tiv_2015 IN (
    SELECT tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(*) > 1
);
