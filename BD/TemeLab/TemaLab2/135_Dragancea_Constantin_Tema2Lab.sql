-- Dragancea Constantin
-- Grupa 135

-- Diagrama HR
-- 1
with filter as (select employee_id
                from employees
                where lower(last_name) like 'k%')
select count(*)
from filter;

-- 2
select last_name, first_name, employee_id, salary
from employees
where salary = (select min(salary)
                from employees);
                
-- 3
select manager_id, last_name
from employees
where department_id = 30
order by last_name;

-- 4
select e1.employee_id, e1.last_name, e1.first_name,
    (select count(*)
        from employees e2
        where e2.manager_id = e1.employee_id) "Nr subalterni"
from employees e1;

-- 5
select employee_id, last_name, first_name
from employees e
where (select count(*)
        from employees
        where last_name = e.last_name) > 1;
        
-- 6
select d.department_id, d.department_name
from departments d
where (select count(distinct job_id)
        from employees
        where d.department_id = department_id) > 1;

-- Diagrama orders
-- 7
select p.prod_id, p.prod_desc, (select sum(qty)
                    from orders_tbl
                    where p.prod_id = prod_id) "Cantitate Totala"
from products_tbl p
where lower(p.prod_desc) like '%plastic%';

-- 8
select last_name||' '||first_name , 'angajat'
from employee_tbl
union
select cust_name, 'client'
from customer_tbl;

-- 9
select distinct p.prod_desc
from products_tbl p, orders_tbl o
where p.prod_id = o.prod_id and
    exists (select *
            from orders_tbl o2
            where o.sales_rep = o2.sales_rep and
                exists (select p2.prod_desc
                from products_tbl p2
                where p2.prod_id = o2.prod_id and
                    lower(p2.prod_desc) like '% p%'));

-- 10
select cust_name
from customer_tbl c, orders_tbl o
where c.cust_id = o.cust_id and
    to_char(o.ord_date, 'dd') = 17;

-- 11
select e.last_name, e.first_name, e2.bonus
from employee_tbl e, employee_pay_tbl e2
where e.emp_id = e2.emp_id and
    nvl(e2.salary, 0) < 32000 and
    nvl(17 * e2.bonus, 0) < 32000;
    
-- 12
select e.last_name, nvl(sum(o.qty), 0) "Cantitate"
from employee_tbl e, orders_tbl o
where e.emp_id = o.sales_rep (+)
group by e.emp_id, e.last_name
having nvl(sum(o.qty), 0) > 50 or
    sum(o.qty) is null;

-- 13
with filter as (select e.last_name, e2.salary, max(o.ord_date) as data, count(o.ord_num) as nr_comenzi
        from employee_tbl e, employee_pay_tbl e2, orders_tbl o
        where e.emp_id = e2.emp_id and o.sales_rep = e.emp_id
        group by e.emp_id, e.last_name, e2.salary, o.sales_rep)
select last_name, salary, data
from filter
where nr_comenzi > 1;

-- 14
select p.*
from products_tbl p
where cost > (select avg(cost)
            from products_tbl);

-- 15
select e1.last_name, e1.first_name, e2.salary, e2.bonus,
    (select sum(salary) from employee_pay_tbl) as total_salary,
    (select sum(bonus) from employee_pay_tbl) as total_bonus
from employee_tbl e1, employee_pay_tbl e2
where e1.emp_id = e2.emp_id;

-- 16
with filter as (select sales_rep, count(ord_num) as nr_comenzi
                from orders_tbl
                group by sales_rep)
select distinct city
from employee_tbl e, filter f
where e.emp_id = f.sales_rep and
    f.nr_comenzi = (select max(nr_comenzi)
                    from filter);

-- 17
select e.emp_id, e.last_name, count(decode(to_char(o.ord_date, 'mm'), 9, 1)) as septembrie,
    count(decode(to_char(o.ord_date, 'mm'), 10, 1)) as octombrie
from employee_tbl e, orders_tbl o
where e.emp_id = o.sales_rep
group by e.emp_id, e.last_name;

-- 18
select c.cust_name, c.cust_city
from customer_tbl c
where regexp_like(c.cust_address, '^\d') and
    not exists (select *
                from orders_tbl
                where c.cust_id = cust_id);

-- 19
select distinct e.emp_id, e.last_name, e.city,
    c.cust_id, c.cust_name, c.cust_city
from employee_tbl e, customer_tbl c
where e.city != c.cust_city and
    exists (select *
            from orders_tbl o
            where e.emp_id = o.sales_rep and c.cust_id = o.cust_id);

-- 20
select round(sum(salary) / count(*), 2) as medie
from employee_pay_tbl;

-- 21
-- este corect
SELECT CUST_ID, CUST_NAME 
FROM CUSTOMER_TBL
WHERE CUST_ID =
(SELECT CUST_ID
FROM ORDERS_TBL
WHERE ORD_NUM = '16C17');

-- nu este corect
SELECT EMP_ID, SALARY
FROM EMPLOYEE_PAY_TBL
WHERE SALARY BETWEEN '20000'
AND (SELECT SALARY
FROM EMPLOYEE_ID
WHERE SALARY = '40000');

-- 22
select e1.last_name, e2.pay_rate
from employee_tbl e1, employee_pay_tbl e2
where e1.emp_id = e2.emp_id and
    nvl(pay_rate, 0) > (select max(e22.pay_rate)
                        from employee_pay_tbl e22, employee_tbl e11
                        where e11.emp_id = e22.emp_id and
                            lower(e11.last_name) like '%ll%');