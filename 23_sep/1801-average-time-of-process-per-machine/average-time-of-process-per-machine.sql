# Write your MySQL query statement below
Select f.machine_id, ROUND(AVG(f.time), 3) processing_time
FROM (
    SELECT t1.machine_id, t1.timestamp-t2.timestamp AS time
    FROM Activity t1, Activity t2
    WHERE t1.machine_id=t2.machine_id
    AND t1.process_id=t2.process_id
    AND t1.activity_type="end"
    AND t2.Activity_type="start"
) as f
GROUP BY machine_id
ORDER BY AVG(f.time)
