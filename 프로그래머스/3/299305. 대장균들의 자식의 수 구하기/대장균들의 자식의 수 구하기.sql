-- 코드를 작성해주세요
select ed1.id, count(ed2.id) as child_count
from ECOLI_DATA as ed1
left join ECOLI_DATA as ed2
on ed1.id = ed2.parent_id
group by ed1.id
order by ed1.id;