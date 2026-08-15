# Write your MySQL query statement below
select s.student_id ,student_name ,sub.subject_name ,
count(E.subject_name) as attended_exams
from Students s cross join Subjects sub left join Examinations E
on s.student_id=E.student_id and sub.subject_name=E.subject_name
group by  s.student_id,s.student_name,sub.subject_name 
order by s.student_id,sub.subject_name;