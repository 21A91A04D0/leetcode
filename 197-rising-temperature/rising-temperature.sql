# Write your MySQL query statement below
SELECT a.id
FROM weather w,weather a
WHERE DATEDIFF(a.recordDate,w.recordDate) = 1 AND a.temperature > w.temperature;