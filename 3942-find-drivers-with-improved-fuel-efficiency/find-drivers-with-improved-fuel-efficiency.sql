# Write your MySQL query statement below

WITH Q AS (SELECT driver_id , AVG(
    CASE WHEN EXTRACT(MONTH FROM trip_date) in (1,2,3,4,5,6)
    THEN distance_km/fuel_consumed
    END
) as first_half_avg , AVG(
    CASE WHEN EXTRACT(MONTH FROM trip_date) in (7,8,9,10,11,12)
    THEN distance_km/fuel_consumed
    END
) as second_half_avg FROM trips
GROUP BY driver_id)

SELECT Q.driver_id , D.driver_name ,ROUND(Q.first_half_avg,2) as first_half_avg,ROUND(Q.second_half_avg,2) as second_half_avg,
ROUND(Q.second_half_avg -Q.first_half_avg,2) as efficiency_improvement FROM Q
JOIN drivers D 
ON Q.driver_id=D.driver_id
WHERE Q.first_half_avg is NOT NULL AND Q.second_half_avg IS NOT NULL AND Q.second_half_avg >Q.first_half_avg ORDER BY efficiency_improvement DESC , driver_name ;