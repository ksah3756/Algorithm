-- 코드를 입력하세요
# 1. start_date가 2022-08부터 2022-10인 car_id 별로 개수 세기
with cte as (select car_id
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where start_date >= '2022-08-01' and start_date < '2022-11-01'
group by car_id
having count(car_id) >= 5)

select month(start_date) as month, car_id, count(car_id) as records
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where start_date >= '2022-08-01' and start_date < '2022-11-01'
and car_id in (select car_id from cte)
group by month(start_date), car_id
order by month asc, car_id desc;