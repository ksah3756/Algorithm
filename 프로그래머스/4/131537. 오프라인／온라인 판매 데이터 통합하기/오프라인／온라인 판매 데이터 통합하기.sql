-- 코드를 입력하세요
SELECT date_format(sales_date, '%Y-%m-%d') as sales_date, product_id, user_id, sales_amount
from (
    select sales_date, product_id, user_id, sales_amount
    from online_sale
    where sales_date >= '2022-03-01' and sales_date < '2022-04-01'
    
    union all
    
    select sales_date, product_id, null as user_id, sales_amount
    from offline_sale
    where sales_date >= '2022-03-01' and sales_date < '2022-04-01'
) as merged
order by sales_date asc, product_id asc, user_id asc;
