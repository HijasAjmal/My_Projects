1.	Show the student count for each active school. 
	Tables involved : students, schools

a.	SELECT name, count(students.id) 
	FROM schools 
	inner join students
	on schools.id = school_id
	where schools.is_deleted = '0' 
	group by name;	


2.	Select any one school and show the names of the students who have unpaid fees, group concat the names of the fee collections which are unpaid by the student.
	Tables involved : finance_fees, finance_fee_collections, students, schools

a.	select t1.name, first_name, last_name,count(f1.fee_collection_id) as Total_number_of_dues, group_concat(f2.name) as Pending_fees
	from schools as t1
	inner join students as s1 on t1.id = s1.school_id
	inner join finance_fees as f1 on s1.id = f1.student_id 
	inner join finance_fee_collections as f2 on f1.fee_collection_id = f2.id
    	where t1.id = '1' and f1.school_id = '1' and is_paid = '0'
	group by s1.id;



3.	Select any one school and show the total number of absentees for each student of that school for a given period of time in the descending order.
	Tables involved : attendances, students, schools     

a.	select t1.name, first_name, middle_name, last_name, count(a1.student_id) as Absent_count
	from schools as t1
	inner join attendances as a1 on t1.id = a1.school_id and a1.school_id = '2' 
	inner join students as s1 on s1.id = a1.student_id and (a1.afternoon = '0' or a1.forenoon = '0')
    	where month_date between '2012-05-08' and '2015-05-08'
	group by s1.id;



4.	Select any one exam group and show the list of all the students with their total marks in descending order.
	Tables involved : exam_groups, exams, exam_scores, students

a.	select exam_groups.name, students.first_name, students.middle_name, students.last_name, sum(e1.marks) as Marks
	from  exams, exam_groups, students
	inner join exam_scores as e1 on students.id = e1.student_id
	where exam_groups.school_id = '4' and exams.exam_group_id = '1' and exam_groups.id = exams.exam_group_id and exam_groups.batch_id = students.batch_id and exams.exam_group_id = e1.exam_id
	group by students.id
	order by Marks asc;




5.	Select any one school and show all courses and group concat the subject names available for each batch of that course.
	Tables involved : schools, courses, batches, subjects

a.	select t1.name, course_name, b1.name, group_concat(s1.name)
	from  schools as t1
	inner join courses as c1 on t1.id = '3' and t1.id = c1.school_id 
	inner join batches as b1 on c1.id = b1.course_id 
	inner join subjects as s1 on b1.id = s1.batch_id
	group by  course_name;

