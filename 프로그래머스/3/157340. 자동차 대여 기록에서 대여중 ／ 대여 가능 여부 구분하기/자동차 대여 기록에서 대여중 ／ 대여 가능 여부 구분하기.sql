-- 코드를 입력하세요
-- START_DATE <= 2022-10-16 < END_DATE 이면 대여중

SELECT
    CAR_ID,
    CASE WHEN CAR_ID IN (select car_id 
                         from CAR_RENTAL_COMPANY_RENTAL_HISTORY
                         where '2022-10-16' BETWEEN START_DATE AND END_DATE
                         group by car_id
                        ) then '대여중' else '대여 가능' end AVAILABILITY
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
GROUP BY CAR_ID
ORDER BY CAR_ID DESC;
    
    
    

select CAR_ID, case when car_id in (select CAR_ID 
                          from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
                          where start_date <= '2022-10-16' and end_date >= '2022-10-16' 
                          group by car_id
                          ) then '대여중'
                else '대여 가능' end AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
group by car_id
order by car_id desc