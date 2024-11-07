# Write your MySQL query statement below
SELECT project_id, ROUND(total_years/no_of_projects,2) AS average_years FROM
(SELECT project_id,sum(experience_years) AS total_years,count(*) AS no_of_projects 
FROM Project p LEFT JOIN Employee e 
ON p.employee_id = e.employee_id
GROUP BY project_id) AS temp;