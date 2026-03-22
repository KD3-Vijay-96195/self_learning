``` sql

Important Considerations while designing the process:
1)	Maximum number of centers = 3
2)	Max no of courses = 3
3)	Seat capacity for each course = 3
4)	No of preferences allowed = 2


--Created ER DIAGRAM 

 -- eraser.io ER-DIAGRAM code.

    notation crows-foot
colorMode pastel
title CDAC ADMISSION PROCESS

ccat_result [color: red, icon: user] {
  student_id int pk
  rank int    
}

preferences [color: purple, icon: list] {
  preference_id int pk
  student_id int fk
  preference_no int
  centre_course_id int fk
}

centre_course [color: yellow, icon: database] {
  centre_course_id int pk
  centre_name varchar
  course_name varchar
  seats_available int
}

allocation_result [color: green, icon: check-circle] {
  allocation_id int pk
  student_id int fk
  centre_course_id int fk
}

ccat_result.student_id < preferences.student_id

centre_course.centre_course_id < preferences.centre_course_id

allocation_result.centre_course_id > centre_course.centre_course_id

allocation_result.student_id - ccat_result.student_id


-- Created ccat_result table.

CREATE TABLE ccat_result (
    student_id INT AUTO_INCREMENT PRIMARY KEY,
    ccat_rank INT NOT NULL
);

-- created centre-course table

CREATE TABLE centre_course (
    centre_course_id INT AUTO_INCREMENT PRIMARY KEY,
    centre_name VARCHAR(100) NOT NULL,
    course_name VARCHAR(50) NOT NULL,
    seats_available INT NOT NULL
);



-- created preference table and given course_id and student_id as foreign key into it. we combined centre_course to form a unique id for each centre_course pair, to reduce the joining later.

CREATE TABLE preferences (
    preference_id INT AUTO_INCREMENT PRIMARY KEY,
    student_id INT NOT NULL,
    preference_no INT NOT NULL,
    centre_course_id INT NOT NULL,
    
    CONSTRAINT fk_student
        FOREIGN KEY (student_id)
        REFERENCES ccat_result(student_id),
        
    CONSTRAINT fk_centre
        FOREIGN KEY (centre_course_id)
        REFERENCES centre_course(centre_course_id)
);

-- added unique constraint so that a student can not give same preference number twice.

ALTER TABLE preferences
ADD UNIQUE(student_id, preference_no);


-- created Allocation-result table and assigned centre_course-id and student_id as foreign keys

CREATE TABLE allocation_result (
    allocation_id INT AUTO_INCREMENT PRIMARY KEY,
    student_id INT NOT NULL,
    centre_course_id INT NOT NULL,

    CONSTRAINT fk_alloc_student
        FOREIGN KEY (student_id)
        REFERENCES ccat_result(student_id),

    CONSTRAINT fk_alloc_centre
        FOREIGN KEY (centre_course_id)
        REFERENCES centre_course(centre_course_id)
);


 

-- hardcoded data for all tables except allocation_result.


-- centre_course

INSERT INTO centre_course (centre_name, course_name, seats_available) VALUES
('Pune','DAC',3),
('Pune','DBDA',3),
('Pune','AI',3),

('Mumbai','DAC',3),
('Mumbai','DBDA',3),
('Mumbai','AI',3),

('Bangalore','DAC',3),
('Bangalore','DBDA',3),
('Bangalore','AI',3);

-- ccat_result
INSERT INTO ccat_result (ccat_rank) VALUES
(1),(2),(3),(4),(5),
(6),(7),(8),(9),(10),
(11),(12),(13),(14),(15),
(16),(17),(18),(19),(20),
(21),(22),(23),(24),(25),
(26),(27),(28),(29),(30),
(31),(32),(33),(34),(35);



-- preferences

INSERT INTO preferences (student_id, preference_no, centre_course_id) VALUES

(1,1,1),(1,2,4),
(2,1,1),(2,2,2),
(3,1,2),(3,2,5),
(4,1,3),(4,2,6),
(5,1,4),(5,2,7),
(6,1,5),(6,2,8),
(7,1,6),(7,2,9),
(8,1,7),(8,2,4),
(9,1,8),(9,2,5),
(10,1,9),(10,2,6),

(11,1,1),(11,2,7),
(12,1,2),(12,2,8),
(13,1,3),(13,2,9),
(14,1,4),(14,2,1),
(15,1,5),(15,2,2),
(16,1,6),(16,2,3),
(17,1,7),(17,2,4),
(18,1,8),(18,2,5),
(19,1,9),(19,2,6),
(20,1,1),(20,2,7),

(21,1,2),(21,2,8),
(22,1,3),(22,2,9),
(23,1,4),(23,2,1),
(24,1,5),(24,2,2),
(25,1,6),(25,2,3),
(26,1,7),(26,2,4),
(27,1,8),(27,2,5),
(28,1,9),(28,2,6),
(29,1,1),(29,2,4),
(30,1,2),(30,2,5),

(31,1,3),(31,2,6),
(32,1,4),(32,2,7),
(33,1,5),(33,2,8),
(34,1,6),(34,2,9),
(35,1,7),(35,2,1);



-- Cursor Procedure (Allocation Process)

DELIMITER $$

CREATE PROCEDURE allocate_seats()
BEGIN

DECLARE done INT DEFAULT 0;
DECLARE v_student INT;
DECLARE v_pref INT;
DECLARE v_seats INT;

DECLARE student_cursor CURSOR FOR
SELECT student_id
FROM ccat_result
ORDER BY ccat_rank;

DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

OPEN student_cursor;

student_loop: LOOP

FETCH student_cursor INTO v_student;

IF done = 1 THEN
LEAVE student_loop;
END IF;

-- check preference 1
SELECT centre_course_id
INTO v_pref
FROM preferences
WHERE student_id = v_student
AND preference_no = 1;

SELECT seats_available
INTO v_seats
FROM centre_course
WHERE centre_course_id = v_pref;

IF v_seats > 0 THEN

INSERT INTO allocation_result(student_id, centre_course_id)
VALUES(v_student, v_pref);

UPDATE centre_course
SET seats_available = seats_available - 1
WHERE centre_course_id = v_pref;

ELSE

-- check preference 2
SELECT centre_course_id
INTO v_pref
FROM preferences
WHERE student_id = v_student
AND preference_no = 2;

SELECT seats_available
INTO v_seats
FROM centre_course
WHERE centre_course_id = v_pref;

IF v_seats > 0 THEN

INSERT INTO allocation_result(student_id, centre_course_id)
VALUES(v_student, v_pref);

UPDATE centre_course
SET seats_available = seats_available - 1
WHERE centre_course_id = v_pref;

END IF;

END IF;

END LOOP;

CLOSE student_cursor;

END$$

DELIMITER ;


--run the allocation 

CALL allocate_seats();


-- check allocated students

SELECT * FROM allocation_result;

--check remaining seats;



