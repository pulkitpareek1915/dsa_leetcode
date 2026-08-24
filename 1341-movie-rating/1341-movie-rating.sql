# Write your MySQL query statement below
(select  u.name AS results
 from MovieRating m1  JOIN Users  u on u.user_id=m1.user_id
group by u.name order by count(*) desc,name limit 1 )
union all
(select  m2.title  AS results
 from MovieRating m1 join Movies m2 
on m1.movie_id=m2.movie_id WHERE left(created_at,7) = '2020-02'
GROUP BY title
ORDER BY AVG(rating) DESC, title
LIMIT 1);