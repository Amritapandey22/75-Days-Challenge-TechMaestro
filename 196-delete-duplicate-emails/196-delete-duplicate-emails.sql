# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below


DELETE p1
from Person P1,Person P2
where P1.email=P2.email 
and
P1.id>p2.id;