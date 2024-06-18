# Write your MySQL query statement below
SELECT contest_id, ROUND(count(user_id) / (SELECT COUNT(user_id) FROM users) * 100,2) as percentage
FROM register
group by contest_id
order by percentage desc,contest_id asc;
