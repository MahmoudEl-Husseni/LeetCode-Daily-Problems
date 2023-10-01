# Write your MySQL query statement below
SELECT  r.contest_id, 
        ROUND(100 * COUNT(*) / (SELECT COUNT(user_id) FROM Users), 2) AS percentage
FROM Register r
GROUP BY r.contest_id
ORDER BY percentage DESC, contest_id ASC
