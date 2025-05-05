-- 코드를 작성해주세요
select d.id, d.email, d.first_name, d.last_name
from DEVELOPERS d
where EXISTS(
    select 1
    from SKILLCODES s
    where s.name in ('C#', 'Python')
        and d.skill_code & s.code > 0
)
order by d.id;