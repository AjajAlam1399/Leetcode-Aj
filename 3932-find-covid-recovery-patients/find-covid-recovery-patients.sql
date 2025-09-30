WITH first_positive AS (
    SELECT patient_id, MIN(test_date) AS pos_date
    FROM covid_tests
    WHERE result = 'Positive'
    GROUP BY patient_id
),
first_negative AS (
    SELECT t.patient_id, MIN(t.test_date) AS neg_date
    FROM covid_tests t
    JOIN first_positive p 
      ON t.patient_id = p.patient_id
     AND t.test_date > p.pos_date
    WHERE t.result = 'Negative'
    GROUP BY t.patient_id
)
SELECT p.patient_id, p.patient_name, p.age,
       DATEDIFF(n.neg_date, f.pos_date) AS recovery_time
FROM patients p
JOIN first_positive f ON p.patient_id = f.patient_id
JOIN first_negative n ON p.patient_id = n.patient_id
ORDER BY recovery_time ASC, p.patient_name ASC;
