-- 코드를 입력하세요
select food_type, rest_id, rest_name, favorites
from rest_info ri
where favorites = (
    SELECT max(favorites) as max_favorites
    from rest_info
    where food_type = ri.food_type
)
order by food_type desc;