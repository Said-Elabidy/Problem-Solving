
select * from VehicleDetails;
select Distinct Make from Makes;

-- ** 2 **
select * from VehicleDetails
where Year between 1950 and 2000 ;

-- ** 3 **
select count (*) as NumberOfVehicles from VehicleDetails
where Year between 1950 and 2000 ;

-- ** 4 **

select Makes.Make , count(*) as NumberOfVehicles 
from VehicleDetails inner join Makes 
on  Makes.MakeID = VehicleDetails.MakeID 
where Year between 1950 and 2000
group by Makes.Make
order by NumberOfVehicles desc;


-- ** 5 **
--First Solution Using  ( Where )
select  * from (
select Makes.Make , count(*) as NumberOfVehicles 
from VehicleDetails inner join Makes 
on  Makes.MakeID = VehicleDetails.MakeID 
where Year between 1950 and 2000
group by Makes.Make

)R
where R.NumberOfVehicles > 12000
order by R.NumberOfVehicles desc;

--Second Solution Using  (Having) 

select Makes.Make , Count(*) as NumberOfVehicles 
from VehicleDetails inner join Makes 
on Makes.MakeID=VehicleDetails.MakeID 
where Year between 1950 and 2000 
group by Makes.Make
having count(*) > 12000
order by NumberOfVehicles Desc ;

-- ** 6 ** 

select Makes.Make , Count(*) as NumberOfVehicles , (select count(*) from VehicleDetails) as TotalVehicles
from VehicleDetails inner join Makes 
on Makes.MakeID=VehicleDetails.MakeID 
where Year between 1950 and 2000 
group by Makes.Make
order by NumberOfVehicles Desc ;

-- ** 7 ** 


select * ,  cast(NumberOfVehicles as Float) / cast(TotalVehicles as float) as Percentage from 
( 
    select Makes.Make , Count(*) as NumberOfVehicles , (select count(*) from VehicleDetails) as TotalVehicles
   from VehicleDetails inner join Makes 
   on Makes.MakeID=VehicleDetails.MakeID 
   where Year between 1950 and 2000 
   group by Makes.Make
   
 ) R1

   order by NumberOfVehicles Desc;

-- ** 8 ** 
--Get Make, FuelTypeName and Number of Vehicles per FuelType per Make

select Makes.Make , FuelTypes.FuelTypeName , Count(*) as VehiclesNumber 
from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID 
inner join FuelTypes on FuelTypes.FuelTypeID = VehicleDetails.FuelTypeID 
where Year between 1950 and 2000 
group by Makes.Make , FuelTypes.FuelTypeName
order by Makes.Make;

-- ** 9 ** 
--Get all vehicles that runs with GAS

select VehicleDetails.* , FuelTypes.FuelTypeName from VehicleDetails inner join 
FuelTypes on FuelTypes.FuelTypeID = VehicleDetails.FuelTypeID 
where VehicleDetails.FuelTypeID = 14 ;

-- ** 10 ** 
-- Get all Makes that runs with GAS

select distinct  Makes.Make , FuelTypes.FuelTypeName from VehicleDetails 
inner join  Makes on Makes.MakeID = VehicleDetails.MakeID inner join FuelTypes on FuelTypes.FuelTypeID = VehicleDetails.FuelTypeID

where FuelTypes.FuelTypeID = 14 
order by Makes.Make ;

-- ** 11 ** 
-- Get Total Makes that runs with GAS

 select count(*) as TotalVehiclesRunWithGas from 
 (
 select Distinct MakeID from VehicleDetails
 where FuelTypeID = 14
 ) R1 

 -- ** 12 ** 
 --  Count Vehicles by make and order them by NumberOfVehicles from high to low

 select Makes.Make , Count(*) as TotalOfVehicles from VehicleDetails inner join Makes 
 on Makes.MakeID = VehicleDetails.MakeID 
 group by Makes.Make
 order by Count(*) desc ;


  -- ** 13 ** 
 --   Get all Makes/Count Of Vehicles that manufactures more than 20K Vehicles

  select Makes.Make , Count(*) as TotalOfVehicles from VehicleDetails inner join Makes 
 on Makes.MakeID = VehicleDetails.MakeID 
 group by Makes.Make
 having Count(*) >20000
 order by Count(*) desc ;

 -- Second Solution Using WHERE

Select * From (

Select Makes.Make, Count(*) as NumberOfVehicles From Makes
Inner Join VehicleDetails On VehicleDetails.MakeID = Makes.MakeID
Group By Makes.Make

) R

Where R.NumberOfVehicles > 20000

-- ** 14 ** 
-- Get all Makes with make starts with 'B'

select Make from Makes 
where Make like 'B%';

-- Problem 15: Get all Makes with make ends with 'W'

select Make from Makes
where Make like '%M';


-- Problem 16: Get all Makes that manufactures DriveTypeName = FWD

select distinct  Makes.Make , DriveTypes.DriveTypeName from VehicleDetails join Makes 
on Makes.MakeID = VehicleDetails.MakeID join DriveTypes on DriveTypes.DriveTypeID = VehicleDetails.DriveTypeID
where DriveTypes.DriveTypeName = 'FWD'

-- Problem 17: Get total Makes that Mantufactures DriveTypeName=FWD

select count(*) as TotalVehiclesWithFWD from 
(
select distinct  Makes.Make , DriveTypes.DriveTypeName from VehicleDetails join Makes 
on Makes.MakeID = VehicleDetails.MakeID join DriveTypes on DriveTypes.DriveTypeID = VehicleDetails.DriveTypeID
where DriveTypes.DriveTypeName = 'FWD'
  ) R1

  --  Problem 18: Get total vehicles per DriveTypeName Per Make and order them per make asc then per total Desc

  select distinct Makes.Make , DriveTypes.DriveTypeName  ,count(*) TotalVehicles  from VehicleDetails join 
  DriveTypes on DriveTypes.DriveTypeID = VehicleDetails.DriveTypeID 
  join Makes on Makes.MakeID = VehicleDetails.MakeID 
  group by DriveTypes.DriveTypeName , Makes.Make
  order by Makes.Make , Count(*)Desc;

  --   Problem 19: Get total vehicles per DriveTypeName Per Make then filter only results with total > 10,000

  select distinct Makes.Make , DriveTypes.DriveTypeName  ,count(*) TotalVehicles  from VehicleDetails join 
  DriveTypes on DriveTypes.DriveTypeID = VehicleDetails.DriveTypeID 
  join Makes on Makes.MakeID = VehicleDetails.MakeID 
  group by DriveTypes.DriveTypeName , Makes.Make
  having Count(*) >10000
  order by Makes.Make , Count(*)Desc;

  -- Problem 20: Get all Vehicles that number of doors is not specified

  select * from VehicleDetails 
  where VehicleDetails.NumDoors is NULL ;

  -- Problem 21: Get Total Vehicles that number of doors is not specified 

  select count(*) as TotalWithNoSpecifiedDoors  from VehicleDetails
  where NumDoors is NULL ;

  -- Problem 22: Get percentage of vehicles that has no doors specified

  select 
  (
  cast ((select  count(*) as TotalWithNoSpecifiedDoors from VehicleDetails where NumDoors is NULL )as float)
  /
  cast ((select  count(*) from VehicleDetails as TotalVehicles  )as float)
  )

  -- Another Solution
  Select Perc =  (Select Count (*) from VehicleDetails where NumDoors is null) * 1. / (Select Count (*) from VehicleDetails )

  -- Problem 23: Get MakeID , Make, SubModelName for all vehicles that have SubModelName 'Elite'

 select VehicleDetails.MakeID , Makes.Make , SubModels.SubModelName from VehicleDetails
 inner join Makes on Makes.MakeID = VehicleDetails.MakeID 
 inner join SubModels on SubModels.SubModelID = VehicleDetails.SubModelID 
 where SubModels.SubModelName = 'Elite' ;

 -- OR

  select  Makes.* , SubModels.SubModelName from VehicleDetails
 inner join Makes on Makes.MakeID = VehicleDetails.MakeID 
 inner join SubModels on SubModels.SubModelID = VehicleDetails.SubModelID 
 where SubModels.SubModelName = 'Elite' ;

 --   Problem 24: Get all vehicles that have Engines > 3 Liters and have only 2 doors

select * from VehicleDetails
where Engine_Liter_Display > 3 and NumDoors =2 ;

-- Problem 25: Get make and vehicles that the engine contains 'OHV' and have Cylinders = 4

select Makes.Make , * from VehicleDetails inner join 
Makes on Makes.MakeID = VehicleDetails.MakeID 
where VehicleDetails.Engine like '%OHV%' and VehicleDetails.Engine_Cylinders =4 ;

 --  Problem 27: Get all vehicles that their Body is 'Coupe' or 'Hatchback' or 'Sedan'

select Bodies.BodyName , VehicleDetails.* from VehicleDetails
join Bodies on Bodies.BodyID = VehicleDetails.BodyID
where Bodies.BodyName in ('Coupe' , 'Hatchback' , 'Sedan' );
 

 -- Problem 28: Get all vehicles that their body is 'Coupe' or 'Hatchback' or 'Sedan' and manufactured in year 2008 or 2020 or 2021

 select Bodies.BodyName , VehicleDetails.* from VehicleDetails
join Bodies on Bodies.BodyID = VehicleDetails.BodyID
where Bodies.BodyName in ('Coupe' , 'Hatchback' , 'Sedan' )
and 
 VehicleDetails.Year in (2008 , 2020 , 2021);

 -- Problem 29: Return found=1 if there is any vehicle made in year 1950

 select Found =1 
 where 
 exists
 ( 
 select top 1 * from VehicleDetails where Year =1950 
 )

 -- Problem 30: Get all Vehicle_Display_Name, NumDoors and add extra column to describe number of doors by words, and if door is null display 'Not Set'

Select Vehicle_Display_Name, NumDoors, DoorDescription =
Case 
	When NumDoors = 0 Then 'Zero Doors'
	When NumDoors = 1 Then 'One Door'
	When NumDoors = 2 Then 'Two Doors'
	When NumDoors = 3 Then 'Three Doors'
	When NumDoors = 4 Then 'Four Doors'
	When NumDoors = 5 Then 'Five Doors'
	When NumDoors = 6 Then 'Six Doors'
	When NumDoors = 8 Then 'Eight Doors'
	Else 'NOT SET'
End
From VehicleDetails

-- Problem 31: Get all Vehicle_Display_Name, year and add extra column to calculate the age of the car then sort the results by age desc.

select VehicleDetails.Vehicle_Display_Name , VehicleDetails.Year , VehicleAge = Year(getdate()) -  VehicleDetails.Year  
from VehicleDetails
order by VehicleAge desc;

--  Problem 32: Get all Vehicle_Display_Name, year, Age for vehicles that their age between 15 and 25 years old

select * from
(
select VehicleDetails.Vehicle_Display_Name , VehicleDetails.Year , Age = Year(getdate()) -  VehicleDetails.Year  
from VehicleDetails

) R1
where R1.Age between 15 and 25.
order by Age desc;

--  Problem 33: Get Minimum Engine CC , Maximum Engine CC , and Average Engine CC of all Vehicles

select  Min(VehicleDetails.Engine_CC) as MinimumCC , Max (VehicleDetails.Engine_CC) as MaximumCC,
AVG(VehicleDetails.Engine_CC) as AverageCC from VehicleDetails ;

 -- Problem 34: Get all vehicles that have the minimum Engine_CC

 select VehicleDetails.* from VehicleDetails
 where Engine_CC = ( select Min(Engine_CC) as MinimumCC from VehicleDetails ) ;

 -- Problem 35: Get all vehicles that have the Maximum Engine_CC

 select VehicleDetails.* from VehicleDetails
 where Engine_CC = (Select Max(Engine_CC) from VehicleDetails) ;

 -- Problem 36: Get all vehicles that have Engin_CC below average

select VehicleDetails.* from VehicleDetails
where Engine_CC < (Select AVG(Engine_CC) from VehicleDetails );

 -- Problem 37: Get total vehicles that have Engin_CC above average
 select Count(*) as TotalVehiclesThatHaveEngineCCAboveAverage from
 (
 select VehicleDetails.* from VehicleDetails
where Engine_CC > (Select AVG(Engine_CC) from VehicleDetails )
)R1  ;


 -- Problem 38: Get all unique Engin_CC and sort them Desc 

 select distinct VehicleDetails.Engine_CC from VehicleDetails
 order by Engine_CC Desc ;

 -- Problem 39: Get the maximum 3 Engine CC

 select distinct top 3  VehicleDetails.Engine_CC from VehicleDetails
 order by Engine_CC Desc ;
 

 -- Problem 40: Get all vehicles that has one of the Max 3 Engine CC

 select VehicleDetails.* from VehicleDetails
 where Engine_CC in (select distinct top 3  VehicleDetails.Engine_CC from VehicleDetails order by Engine_CC Desc ) ;

 -- Problem 41: Get all Makes that manufactures one of the Max 3 Engine CC
 
 select distinct  Makes.Make from VehicleDetails
 inner join Makes on Makes.MakeID = VehicleDetails.MakeID
 where Engine_CC in (select distinct top 3  VehicleDetails.Engine_CC from VehicleDetails order by Engine_CC Desc ) ;

 -- Problem 42: Get a table of unique Engine_CC and calculate tax per Engine CC
 	-- 0 to 1000    Tax = 100
	-- 1001 to 2000 Tax = 200
	-- 2001 to 4000 Tax = 300
	-- 4001 to 6000 Tax = 400
	-- 6001 to 8000 Tax = 500
	-- Above 8000   Tax = 600
	-- Otherwise    Tax = 0

	select distinct Engine_CC ,  Tax = 
	Case 
	when Engine_CC between 0 and 1000 Then 100
	when Engine_CC between 1001 and 2000 then 200
	when Engine_CC between 2001 and 4000 then 300
	when Engine_CC between 4001 and 6000 then 400
	when Engine_CC between 6001 and 8000 then 500
	when Engine_CC > 8000 then 600
	else 0
	end 

	from VehicleDetails
	order by Engine_CC desc ;

 -- Problem 43: Get Make and Total Number Of Doors Manufactured Per Make

 select Makes.Make , Sum(VehicleDetails.NumDoors) as TotalDoors from VehicleDetails
 inner join Makes on Makes.MakeID = VehicleDetails.MakeID 
 group by Makes.Make 
 order by Sum(VehicleDetails.NumDoors) desc ;

 -- Problem 44: Get Total Number Of Doors Manufactured by 'Ford'
 
  select Makes.Make , Sum(VehicleDetails.NumDoors) as TotalDoors from VehicleDetails
 inner join Makes on Makes.MakeID = VehicleDetails.MakeID 
 group by Makes.Make 
 having Makes.Make = 'Ford' ;

 -- Problem 45: Get Number of Models Per Make

select Makes.Make , count(*) NumberOfModels from MakeModels inner join 
Makes on Makes.MakeID = MakeModels.MakeID 
group by Makes.Make
order by Count(*) desc ;

 --   Problem 46: Get the highest 3 manufacturers that make the highest number of models

select top 3 Makes.Make , count(*) NumberOfModels from MakeModels inner join 
Makes on Makes.MakeID = MakeModels.MakeID 
group by Makes.Make
order by Count(*) desc ;

--  Problem 47: Get the highest number of models manufactured

select top 1 count(*) as HeighestNumberOfModels from MakeModels
group by MakeModels.MakeID
order by Count(*) desc ;

-- Problem 48: Get the highest Manufacturers manufactured the highest number of models

select Makes.Make from MakeModels inner join Makes 
on Makes.MakeID = MakeModels.MakeID 
group by Makes.Make
having count(MakeModels.ModelID) = (select top 1 count(*) as HeighestNumberOfModels from MakeModels
group by MakeModels.MakeID
order by Count(*) desc ) ;

 -- Problem 49: Get the Lowest Manufacturers manufactured the lowest number of models

 select Makes.Make from MakeModels inner join Makes 
on Makes.MakeID = MakeModels.MakeID 
group by Makes.Make
having count(MakeModels.ModelID) = (select top 1 count(*) as HeighestNumberOfModels from MakeModels
group by MakeModels.MakeID
order by Count(*)  ) ;

--   Problem 50: Get all Fuel Types , each time the result should be showed in random order

select FuelTypes.FuelTypeName from FuelTypes
order by newid();


							