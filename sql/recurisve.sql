drop table parentof;

delete from parentof where true;

insert into parentof values
('alice', 'carol', 1945),
('bob', 'carol', 1945),
('carol', 'dave', 1970),
('carol','george', 1972),
('dave','mary',2000),
('eve','mary',2000),
('mary','frank',2020);

create table parentof (
	parent varchar(10),
	child varchar (10),
	birth_year decimal(4),
	primary key(parent, child)
);

with recursive descendant
as (
	select concat(parent,'->',child) as lineage, child as c
	from parentof where parent='alice'
	union all
	select concat(parent,'->',child) as lineage, child as c
	from descendant, parentof
	where descendant.c=parentof.parent
)
select lineage, c from descendant;
