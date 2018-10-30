1.	Show the student count for each active school.
	Tables involved : students, schools

a.	SELECT name, count(students.id) FROM schools, students where schools.is_deleted = '0' and schools.id = school_id group by name;	


2.	Select any one school and show the names of the students who have unpaid fees, group concat the names of the fee collections which are unpaid by the student.
	Tables involved : finance_fees, finance_fee_collections, students, schools


a.	SELECT schools.name, first_name, last_name, count(fee_collection_id) as Total_number_of_dues, group_concat(finance_fee_collections.name) as Pending_fees
	FROM finance_fees, schools, students, finance_fee_collections
	where schools.id = '1' and finance_fees.school_id = '1' and students.id = finance_fees.student_id and is_paid = '0' and fee_collection_id = finance_fee_collections.id
	group by students.id;

3.	Select any one school and show the total number of absentees for each student of that school for a given period of time in the descending order.
	Tables involved : attendances, students, schools     

a.	select schools.name, first_name, middle_name, last_name, count(attendances.student_id) 
	from attendances, schools, students 
	where schools.id = attendances.school_id and attendances.school_id = '3' and students.id = attendances.student_id and (attendances.afternoon = '0' or attendances.forenoon = '0')
	group by students.id;         


4.	Select any one exam group and show the list of all the students with their total marks in descending order.
	Tables involved : exam_groups, exams, exam_scores, students

a.	select exam_groups.name, students.first_name, students.middle_name, students.last_name 
from  exams, exam_groups, exam_scores, students
where exam_groups.school_id = '4' and exam_groups.id = '1' and exams.exam_group_id = exam_groups.id and exam_groups.batch_id = students.batch_id;



5.	Select any one school and show all courses and group concat the subject names available for each batch of that course.
	Tables involved : schools, courses, batches, subjects

a.	select schools.name, course_name, batches.name, group_concat(subjects.name)
	from  schools, courses, batches, subjects
	where schools.id = '3' and schools.id = courses.school_id and courses.id = batches.course_id and batches.id = subjects.batch_id
	group by  course_name;

