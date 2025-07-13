-- 코드를 입력하세요
SELECT extract(month from start_date) as month, car_id, count(*) as records
from (
    select car_id, start_date,
    count(*) over (partition by car_id) as rental_count
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where start_date >= date '2022-08-01' and start_date < date '2022-11-01'
) cte
where rental_count >= 5
group by extract(month from start_date) , car_id
order by extract(month from start_date)  asc, car_id desc;
