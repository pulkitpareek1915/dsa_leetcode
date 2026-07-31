# Write your MySQL query statement below
select d1.name as Department, e1.name as Employee,e1.salary as Salary 
from Employee e1 join Department d1 on e1.departmentId=d1.id
where (e1.departmentId , salary ) in (
    select departmentId,max(salary) from
    Employee group by departmentId
);
