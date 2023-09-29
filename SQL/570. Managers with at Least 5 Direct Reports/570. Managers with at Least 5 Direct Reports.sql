# Write your MySQL query statement below
SELECT mm.name
FROM (
    SELECT m.managerId, COUNT(*) cnt
    FROM Employee e, Employee m
    WHERE e.id=m.managerId
    GROUP BY m.managerId
) m, Employee mm
WHERE m.managerId=mm.id
AND cnt >= 5
