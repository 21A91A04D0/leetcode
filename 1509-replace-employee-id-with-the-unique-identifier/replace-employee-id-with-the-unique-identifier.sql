# Write your MySQL query statement below
SELECT unique_id, name
From Employees
left join EmployeeUNI
on EmployeeUNI.id = employees.id