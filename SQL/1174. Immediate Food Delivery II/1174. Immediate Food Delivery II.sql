# Write your MySQL query statement below
SELECT ROUND(AVG(t.c)*100, 2) AS immediate_percentage
FROM 
(SELECT if(MIN(order_date)=MIN(customer_pref_delivery_date), 1, 0) c
FROM Delivery
GROUP BY customer_id) t
