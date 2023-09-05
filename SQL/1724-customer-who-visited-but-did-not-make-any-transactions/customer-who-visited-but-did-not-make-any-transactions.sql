# Write your MySQL query statement below
SELECT customer_id, COUNT(customer_id) as count_no_trans
FROM Visits v
WHERE v.visit_id NOT IN (SELECT DISTINCT visit_id FROM Transactions)
GROUP BY customer_id;