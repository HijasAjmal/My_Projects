SQL :: Assignment 2

ref: school id 83
-----------------
1) 	show all subject names to be studied by students of all active batches, show student full name and batch full name
	[tables: students, subjects, elective_groups, students_subjects, batches, courses]

a)  select students.first_name, students.last_name, b1.name, group_concat(s2.name) as Subjects, e1.name as Elective
	from students
	inner join batches as b1 on students.batch_id = b1.id
	inner join courses as c1 on b1.course_id = c1.id
	inner join students_subjects as s1 on s1.student_id = students.id
	inner join subjects as s2 on s1.subject_id = s2.id
	inner join elective_groups as e1 on s2.elective_group_id = e1.id
	where students.school_id = '83' and b1.is_active = '1'
	group by students.id;




2) 	show count of subject leaves for students
	[tables: students, subject_leaves]
a)  select t1.first_name, t1.last_name, count(subject_leaves.student_id)
	from students as t1
	inner join subject_leaves on t1.id = subject_leaves.student_id
	where t1.school_id = '83'
	group by t1.id;




3) 	show name of day of absence for student, name of teacher who marked absent
    [tables: students, subject_leaves, employees, subject_leaves_teachers]

a)	select students.first_name, students.last_name, dayname(s1.month_date) as 'Day of Absent' ,group_concat(e1.first_name, ' ', e1.last_name) as 'Teacher'
	from students
	inner join subject_leaves as s1 on s1.student_id = students.id
	inner join employees as e1 on s1.employee_id = e1.id
	where students.school_id = 4
	group by students.id;

4) 	write search query for all students whose name has string 'aman' and has some upaid fees (with or without fine)
	[tables: students, finance_fees, finance_fee_collections, fines, fine_rules]


a)	

5) 	find all students who are receiving any sort of discounts in their fees
	[tables: students, fee_discounts, finance_fees, finance_fee_collections, collection_discounts]

a)	select first_name,last_name, f3.name as 'Fee Category', f1.balance as 'amount', f2.name as 'Discount Category',f3.id
	from students
	inner join collection_discounts as c1 on c1.school_id = 83
	inner join finance_fees as f1 on c1.finance_fee_collection_id = f1.id
	inner join finance_fee_collections as f3 on f3.id = f1.fee_collection_id
	inner join fee_discounts as f2 on f2.receiver_id = students.id
	where students.school_id = 83 and f2.receiver_type = 'Student' 
	group by students.id;



6)  find all students who has atleast once made fee payment using online mode
	[tables: students, finance_transactions]
a)  select t1.first_name, t1.last_name
    from students as t1
    inner join finance_transactions on t1.id = payee_id
    where t1.school_id = '83' and payee_type = 'Student' and payment_mode = 'Online Payment'
    group by t1.id;





7) 	find all students who has either borrowed a book or has book due to return (if has any previous late fines paid)
	[tables: students, book_movement, finance_transactions]

8) 	find all employees who are teacher and has never applied for a leave
	[tables: employees, batch_tutors, employee_attendances]

9) 	show student name, total amount to pay and total fine amount (as of today) for all students who has not completely paid
	[tables: students, finance_fees, finance_fee_collections, fines, fine_rules]

10) fetch all fees (collection) name, actual fees amount, discount amount, fines applicable for a selected student
	[tables: finance_fees, finance_fee_collections, fee_discounts, collection_discounts, collection_particulars, finance_fee_particulars, fines, fine_rules]
a)	select finance_fee_collections.name 
from finance_fee_collections
inner join finance_fees as f1 on f1.fee_collection_id = finance_fee_collections.id
where f1.school_id = 83 and f1.student_id = 5081;