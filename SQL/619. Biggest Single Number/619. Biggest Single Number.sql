# Write your MySQL query statement below
SELECT IF(COUNT(t.num)>0, t.num, null) num FROM (SELECT num
FROM MyNumbers
GROUP BY num
HAVING COUNT(num)=1
ORDER BY num DESC) t
