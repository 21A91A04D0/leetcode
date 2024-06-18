# Write your MySQL query statement below
SELECT employee.name, bonus.bonus
FROM employee
LEFT JOIN bonus
on employee.empId = bonus.empId
where bonus.bonus < 1000 OR bonus.bonus IS NULL