select id, 
case grp
    when 1 then 'CRITICAL'
    when 2 then 'HIGH'
    when 3 then 'MEDIUM'
    when 4 then 'LOW'
    end as colony_name
from (
    select id, ntile(4) over (order by size_of_colony desc) as grp
     from ecoli_data
) as sub
order by id
