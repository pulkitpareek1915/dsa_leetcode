# Write your MySQL query statement below
select person_name from (
    select person_name,sum(weight) over (order by turn) as rs from Queue
)q
where rs<=1000
order by rs desc limit 1;