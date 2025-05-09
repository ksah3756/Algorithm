-- 코드를 작성해주세요
select count(*) as FISH_COUNT
from FISH_INFO fi
join FISH_NAME_INFO fni
on fi.fish_type = fni.fish_type
where fni.fish_name in ('BASS', 'SNAPPER')