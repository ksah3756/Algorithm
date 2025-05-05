-- 코드를 입력하세요
# select ai.name, ao.name, ai.datetime, ao.datetime
# from ANIMAL_INS ai
# left join ANIMAL_OUTS ao
# on ai.name = ao.name


SELECT ai.name, ai.datetime
from ANIMAL_INS ai
left join ANIMAL_OUTS ao
on ai.animal_id = ao.animal_id
where ao.animal_id is null
order by ai.datetime
limit 3