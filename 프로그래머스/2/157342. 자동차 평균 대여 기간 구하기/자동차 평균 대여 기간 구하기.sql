-- 코드를 입력하세요
SELECT c.car_id, c.average_duration
from (
    select car_id, round(sum(datediff(end_date, start_date)+1) / count(*), 1) as average_duration
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    group by car_id
) as c
where c.average_duration >= 7
order by c.average_duration desc, c.car_id desc