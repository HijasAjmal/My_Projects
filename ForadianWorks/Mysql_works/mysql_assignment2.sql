SQL :: Assignment 2

ref: school id 83
---------------------------------------------------------------------------------------------------------------------------
1) 	show all subject names to be studied by students of all active batches, show student full name and batch full name
	[tables: students, subjects, elective_groups, students_subjects, batches, courses]

a)  select s1.first_name, s1.last_name, b1.name, group_concat(s3.name) as Subjects, e1.name as Elective
	from courses
	inner join batches as b1 on courses.id = b1.course_id
	inner join students as s1 on b1.id = s1.batch_id
	inner join students_subjects as s2 on s1.id = s2.student_id
	inner join subjects as s3 on s2.subject_id = s3.id
	inner join elective_groups as e1 on s3.elective_group_id = e1.id
	where courses.school_id = '4' and b1.is_active = '1'
  group by b1.id;




2) 	show count of subject leaves for students
	[tables: students, subject_leaves]
a)  select t1.first_name, t1.last_name, subject_leaves.subject_id, count(subject_leaves.student_id) as 'Absence Count'
	from students as t1
	inner join subject_leaves on t1.id = subject_leaves.student_id
	where t1.school_id = '83'
	group by t1.id;




3) 	show name of day of absence for student, name of teacher who marked absent
    [tables: students, subject_leaves, employees, subject_leaves_teachers]

a)	select students.first_name, students.last_name, dayname(s1.month_date) as 'Day of Absent' ,e1.first_name as 'Teacher'
	from students
	inner join subject_leaves as s1 on s1.student_id = students.id
	inner join subject_leaves_teachers as s2 on s2.employee_id = s1.employee_id and s1.id = s2.subject_leave_id
	inner join employees as e1 on s1.employee_id = e1.id;





4) 	write search query for all students whose name has string 'aman' and has some upaid fees (with or without fine)
	[tables: students, finance_fees, finance_fee_collections, fines, fine_rules]

a)	select first_name,last_name, f2.name as 'Fee Category', f1.balance as 'amount', f3.name as 'Fine Category', f4.fine_amount as 'Fine Amount', f4.fine_days as 'Fine Days'
	from students
	inner join finance_fees as f1 on f1.student_id = students.id
	inner join finance_fee_collections as f2 on f2.id = f1.fee_collection_id
	inner join fines as f3 on f2.fine_id = f3.id
	inner join fine_rules as f4 on f3.id = f4.fine_id
	where students.school_id = 4 and f1.balance > 0 and (first_name like '%aman%' or middle_name like '%aman%' or last_name like '%aman%')
	group by f2.id;






5) 	find all students who are receiving any sort of discounts in their fees
	[tables: students, fee_discounts, finance_fees, finance_fee_collections, collection_discounts]

a)	select first_name,last_name, group_concat(f2.name) as 'Fee Category', f1.balance as 'amount', group_concat(f3.name) as 'Discount Category', group_concat(f3.discount) as 'Discount Amount'
	from students
	inner join finance_fees as f1 on f1.student_id = students.id
	inner join finance_fee_collections as f2 on f2.id = f1.fee_collection_id
	inner join collection_discounts as c1 on c1.finance_fee_collection_id = f2.id
	inner join fee_discounts as f3 on c1.fee_discount_id = f3.id
	where students.school_id = 83 and f3.receiver_type = 'Student'
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

a)	select first_name, last_name, b1.user_id, f1.title, b1.book_id
	from students
	inner join book_movements as b1 on students.user_id = b1.user_id
	inner join finance_transactions as f1 on b1.book_id = f1.finance_id
	where students.school_id = 4 and f1.fine_amount > 0
	group by b1.user_id;





8) 	find all employees who are teacher and has never applied for a leave
	[tables: employees, batch_tutors, employee_attendances]

a) 	select first_name,last_name
	from employees
	inner join batch_tutors as b1 on employees.id = b1.employee_id
	inner join employee_attendances as e1 on b1.employee_id != e1.employee_id
	where employees.school_id = 83
	group by employees.id;





9) 	show student name, total amount to pay and total fine amount (as of today) for all students who has not completely paid
	[tables: students, finance_fees, finance_fee_collections, fines, fine_rules]

a)	select first_name,last_name, f2.name as 'Fee Category', f1.balance as 'Amount to pay', f3.name as 'Fine Category', f4.fine_amount as 'Fine Amount', f4.fine_days as 'Fine Days'
	from students
	inner join finance_fees as f1 on f1.student_id = students.id
	inner join finance_fee_collections as f2 on f2.id = f1.fee_collection_id
	inner join fines as f3 on f2.fine_id = f3.id
	inner join fine_rules as f4 on f3.id = f4.fine_id
	where students.school_id = 83 and f1.is_paid = 0
	group by students.id;





10) fetch all fees (collection) name, actual fees amount, discount amount, fines applicable for a selected student
	[tables: finance_fees, finance_fee_collections, fee_discounts, collection_discounts, collection_particulars, finance_fee_particulars, fines, fine_rules]
a)	select f2.name as 'Fee Category', finance_fees.balance as 'Amount', f4.name as 'Fee particular', f4.amount as 'Amount', f3.name as 'Discount Category', f3.discount as 'Discount Amount', finance_fees.student_id, f5.name as 'Fine Category', f6.fine_amount, f6.fine_days
	from finance_fees
	inner join finance_fee_collections as f2 on f2.id = finance_fees.fee_collection_id
	inner join collection_discounts as c1 on c1.finance_fee_collection_id = f2.id
	inner join fee_discounts as f3 on c1.fee_discount_id = f3.id
	inner join collection_particulars as c2 on c2.finance_fee_collection_id = c1.finance_fee_collection_id
	inner join finance_fee_particulars as f4 on c2.finance_fee_particular_id = f4.id
	inner join fines as f5 on f2.fine_id = f5.id
	inner join fine_rules as f6 on f5.id = f6.fine_id
	where finance_fees.school_id = 83 and finance_fees.student_id = 5214 and f3.receiver_type = 'Student'
	group by finance_fees.fee_collection_id;
