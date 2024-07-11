# Write your MySQL query statement below
SELECT w.id
from weather w,weather e
where DATEDIFF(w.recordDate,e.recordDate) = 1 and w.temperature > e.temperature;