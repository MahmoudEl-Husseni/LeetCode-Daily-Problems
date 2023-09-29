# Write your MySQL query statement below
SELECT a.user_id, COALESCE(ROUND(confirmed / _all, 2), 0) confirmation_rate
FROM
(SELECT user_id, COUNT(*) confirmed
FROM Confirmations
WHERE action='confirmed'
GROUP BY user_id) c
RIGHT OUTER JOIN
(SELECT user_id, COUNT(*) _all
FROM Confirmations
GROUP BY user_id) a
on c.user_id=a.user_id
UNION
SELECT s.user_id, 0 AS confirmation_rate
FROM Signups s LEFT OUTER JOIN Confirmations c
ON s.user_id=c.user_id
WHERE c.time_stamp IS NULL
