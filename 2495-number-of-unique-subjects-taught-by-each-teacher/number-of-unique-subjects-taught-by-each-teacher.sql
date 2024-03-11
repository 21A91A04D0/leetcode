# Write your MySQL query statement below
# for each row with unique teacher_id (group by) with the count of distinct subject_id aliasing count as cnt from the Teacher table  
SELECT teacher_id, count(distinct subject_id) as cnt
from Teacher
group by teacher_id;