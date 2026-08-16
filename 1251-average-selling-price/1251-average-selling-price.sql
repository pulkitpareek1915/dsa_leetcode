# Write your MySQL query statement below
select P.product_id , Round((ifnull(sum(P.price*U.units)/sum(U.units),0)),2) as average_price
from Prices P Left join UnitsSold U
on purchase_date between start_date and end_date 
and P.product_id=U.product_id group by P.product_id;