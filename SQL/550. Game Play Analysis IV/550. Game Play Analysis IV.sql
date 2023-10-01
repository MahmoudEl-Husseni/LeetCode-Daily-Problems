# Write your MySQL query statement below
SELECT ROUND(COUNT(DISTINCT n.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2)
AS fraction
FROM Activity n
WHERE n.event_date =
  (
    date_add(
      (SELECT MIN(event_date) 
      FROM Activity t 
      WHERE t.player_id=n.player_id), 
      INTERVAL 1 DAY)
  )
