SQL :: Assignment 2

ref: school id 83
-----------------
 1) show all subject names to be studied by students of all active batches, show student full name and batch full name
	[tables: students, subjects, elective_groups, students_subjects, batches, courses]

a)  select students.first_name, students.last_name, b1.name
    from students
    inner join batches as b1 on students.batch_id = b1.id
    where students.school_id = '83' and b1.is_active = '1'
    group by students.first_name, students.last_name;



 2) show count of subject leaves for students
	[tables: students, subject_leaves]
a)  select t1.first_name, t1.last_name, count(subject_leaves.student_id)
from students as t1
inner join subject_leaves on t1.id = subject_leaves.student_id
where t1.school_id = '83'
group by t1.id;




 3) show name of day of absence for student, name of teacher who marked absent
    [tables: students, subject_leaves, employees, subject_leaves_teachers]

 4) write search query for all students whose name has string 'aman' and has some upaid fees (with or without fine)
	[tables: students, finance_fees, finance_fee_collections, fines, fine_rules]

 5) find all students who are receiving any sort of discounts in their fees
	[tables: students, fee_discounts, finance_fees, finance_fee_collections, collection_discounts]

6)  find all students who has atleast once made fee payment using online mode
	  [tables: students, finance_transactions]
a)  select t1.first_name, t1.last_name
    from students as t1
    inner join finance_transactions on t1.id = payee_id
    where t1.school_id = '83' and payee_type = 'Student' and payment_mode = 'Online Payment'
    group by t1.id;





7) find all students who has either borrowed a book or has book due to return (if has any previous late fines paid)
	[tables: students, book_movement, finance_transactions]

 8) find all employees who are teacher and has never applied for a leave
	[tables: employees, batch_tutors, employee_attendances]

 9) show student name, total amount to pay and total fine amount (as of today) for all students who has not completely paid
	[tables: students, finance_fees, finance_fee_collections, fines, fine_rules]

10) fetch all fees (collection) name, actual fees amount, discount amount, fines applicable for a selected student
	[tables: finance_fees, finance_fee_collections, fee_discounts, collection_discounts, collection_particulars, finance_fee_particulars, fines, fine_rules]
