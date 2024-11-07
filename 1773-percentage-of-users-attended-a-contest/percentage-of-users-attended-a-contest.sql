# Write your MySQL query statement below
SELECT contest_id,ROUND(total*100/(SELECT count(*) FROM Users),2) AS percentage FROM
(SELECT r.contest_id,count(r.user_id) AS total FROM Users u RIGHT JOIN Register r 
ON u.user_id = r.user_id
GROUP BY contest_id) AS temp ORDER BY percentage DESC,contest_id ASC;