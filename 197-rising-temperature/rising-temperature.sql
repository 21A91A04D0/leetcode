# Write your MySQL query statement below
SELECT w.id
FROM weather w
cross join weather a
ON DATEDIFF(w.recordDate,a.recordDate) = 1 AND a.temperature < w.temperature;

