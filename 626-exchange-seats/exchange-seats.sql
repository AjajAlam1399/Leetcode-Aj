WITH total AS (
    SELECT COUNT(*) AS cnt FROM seat
)
SELECT 
    CASE
        WHEN s.id % 2 = 1 AND s.id < t.cnt THEN s.id + 1
        WHEN s.id % 2 = 0 AND s.id < t.cnt THEN s.id - 1
        WHEN s.id = t.cnt AND s.id % 2 = 0 THEN s.id - 1
        ELSE s.id
    END AS id,
    s.student
FROM seat s
CROSS JOIN total t
ORDER BY id;
