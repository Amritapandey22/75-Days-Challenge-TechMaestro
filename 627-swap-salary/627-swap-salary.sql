# Write your MySQL query statement below
#UPDATE salary SET sex = IF(sex = 'm', 'f', 'm')
update salary 
set sex=IF(sex='f','m','f');