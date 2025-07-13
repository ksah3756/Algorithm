
with ctl as (
    select id, fni.fish_name, fi.fish_type, fi.length,
    max(length) over (partition by fish_type) as max_length
    from fish_info fi
    join fish_name_info fni
    on fi.fish_type = fni.fish_type
)

select id, fish_name, length
from ctl
where length = max_length
order by id;