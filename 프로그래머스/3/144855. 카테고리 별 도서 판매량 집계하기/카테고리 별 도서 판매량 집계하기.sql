-- 코드를 입력하세요
SELECT b.category, sum(bs.sales) as total_sales
from book b
join book_sales bs
on b.book_id = bs.book_id
where bs.sales_date >= date '2022-01-01' and bs.sales_date < date '2022-02-01'
group by b.category
order by b.category asc;