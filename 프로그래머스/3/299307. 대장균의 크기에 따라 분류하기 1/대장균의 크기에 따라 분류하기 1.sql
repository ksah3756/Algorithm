-- 코드를 작성해주세요
select ed.id, 
    case when SIZE_OF_COLONY <= 100 then 'LOW'
        when SIZE_OF_COLONY <= 1000 then 'MEDIUM'
        else 'HIGH'
    end as SIZE
from ECOLI_DATA as ed
order by ed.id;