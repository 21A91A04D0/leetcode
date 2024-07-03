# Write your MySQL query statement below
select l.employee_id, l.name,count(r.reports_to) as reports_count, round(avg(r.age)) as average_age
from employees l
JOIN employees r
ON l.employee_id = r.reports_to
group by l.employee_id having reports_count > 0 
order by l.employee_id;

