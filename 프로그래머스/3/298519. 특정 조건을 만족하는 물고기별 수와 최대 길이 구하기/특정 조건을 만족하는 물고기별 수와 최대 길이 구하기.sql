-- 코드를 작성해주세요

select fish_count, max_length, fish_type
from(
    select fish_type, avg(length) length, count(*) fish_count, max(length) max_length
    from fish_info
    group by fish_type
) ft
where length >= 33
order by fish_type asc