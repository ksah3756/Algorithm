-- 코드를 작성해주세요
select child.id, child.genotype, parent.genotype as parent_genotype
from ecoli_data child
join ecoli_data parent on child.parent_id = parent.id
where child.genotype & parent.genotype = parent.genotype
order by child.id