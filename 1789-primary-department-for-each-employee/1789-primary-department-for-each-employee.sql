# Write your MySQL query statement below
select e1.employee_id,e1.department_id from Employee e1
join Employee e2 on e1.employee_id=e2.employee_id
group by e1.employee_id, e1.department_id
 having count(e1.department_id)=1
  OR Max(IF(e1.primary_flag = 'Y', 1, 0)) = 1;