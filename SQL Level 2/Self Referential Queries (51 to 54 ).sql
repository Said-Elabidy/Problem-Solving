select * from Employees;

-- Problem 51: Get all employees that have manager along with Manager's name.

-- Get all employees that have manager along with Manager's name.
-- this will select all data from employees that are managed by someone along with their manager name, 
-- employees that have no manager will not be selected because we used inner join 
-- Note we used inner join on the same table with diffrent alliace.

 select Employees.Name , Employees.Salary , Employees.ManagerID , Managers.Name as ManagerName 
 from Employees inner join Employees as Managers 
 on Employees.ManagerID = Managers.EmployeeID ;

 -- Problem 52: Get all employees that have manager or does not have manager along with Manager's name, incase no manager name show null

  select Employees.Name , Employees.Salary , Employees.ManagerID , Managers.Name as ManagerName 
 from Employees left join Employees as Managers 
 on (Employees.ManagerID = Managers.EmployeeID) ;

 -- Problem 53: Get all employees that have manager or does not have manager along with Manager's name, incase no manager name the same employee name as manager to himself

 SELECT Employees.Name, Employees.ManagerID, Employees.Salary,  
  CASE
    WHEN Managers.Name is Null  THEN Employees.Name
    ELSE Managers.Name
END as ManagerName 
from Employees left join Employees as Managers on Employees.ManagerID =Managers.EmployeeID ;

--   Problem 54: Get All Employees managed by 'Mohammed'

select Employees.Name , Employees.Salary , Employees.ManagerID , Managers.Name 
from Employees inner join Employees as Managers 
on Employees.ManagerID = Managers.EmployeeID 
where Managers.Name = 'Mohammed'
