// server.js

const express = require("express");

const app = express();

app.use(express.json());


// =========================================
// DUMMY DATA
// =========================================

let courses = [
    {
        id: 1,
        courseName: "Java",
        duration: "3 Months"
    },
    {
        id: 2,
        courseName: "NodeJS",
        duration: "2 Months"
    }
];

let students = [
    {
        id: 1,
        studentName: "Rahul",
        courseId: 1
    },
    {
        id: 2,
        studentName: "Priya",
        courseId: 2
    }
];



// =========================================
// COURSE CRUD API
// =========================================


// GET ALL COURSES
app.get("/courses", (req, res) => {

    res.json(courses);

});


// GET SINGLE COURSE
app.get("/courses/:id", (req, res) => {

    const id = parseInt(req.params.id);

    const course = courses.find(c => c.id === id);

    if(course){

        res.json(course);

    }else{

        res.status(404).json({
            message: "Course Not Found"
        });

    }

});


// ADD COURSE
app.post("/courses", (req, res) => {

    const newCourse = req.body;

    courses.push(newCourse);

    res.json({
        message: "Course Added",
        data: courses
    });

});


// UPDATE COURSE
app.put("/courses/:id", (req, res) => {

    const id = parseInt(req.params.id);

    const index = courses.findIndex(c => c.id === id);

    if(index !== -1){

        courses[index] = {
            ...courses[index],
            ...req.body
        };

        res.json({
            message: "Course Updated",
            data: courses[index]
        });

    }else{

        res.status(404).json({
            message: "Course Not Found"
        });

    }

});


// DELETE COURSE
app.delete("/courses/:id", (req, res) => {

    const id = parseInt(req.params.id);

    const index = courses.findIndex(c => c.id === id);

    if(index !== -1){

        const deletedCourse = courses.splice(index, 1);

        res.json({
            message: "Course Deleted",
            data: deletedCourse
        });

    }else{

        res.status(404).json({
            message: "Course Not Found"
        });

    }

});




// =========================================
// STUDENT CRUD API
// =========================================


// GET ALL STUDENTS
app.get("/students", (req, res) => {

    res.json(students);

});


// GET SINGLE STUDENT
app.get("/students/:id", (req, res) => {

    const id = parseInt(req.params.id);

    const student = students.find(s => s.id === id);

    if(student){

        res.json(student);

    }else{

        res.status(404).json({
            message: "Student Not Found"
        });

    }

});


// ADD STUDENT
app.post("/students", (req, res) => {

    const newStudent = req.body;

    students.push(newStudent);

    res.json({
        message: "Student Added",
        data: students
    });

});


// UPDATE STUDENT
app.put("/students/:id", (req, res) => {

    const id = parseInt(req.params.id);

    const index = students.findIndex(s => s.id === id);

    if(index !== -1){

        students[index] = {
            ...students[index],
            ...req.body
        };

        res.json({
            message: "Student Updated",
            data: students[index]
        });

    }else{

        res.status(404).json({
            message: "Student Not Found"
        });

    }

});


// DELETE STUDENT
app.delete("/students/:id", (req, res) => {

    const id = parseInt(req.params.id);

    const index = students.findIndex(s => s.id === id);

    if(index !== -1){

        const deletedStudent = students.splice(index, 1);

        res.json({
            message: "Student Deleted",
            data: deletedStudent
        });

    }else{

        res.status(404).json({
            message: "Student Not Found"
        });

    }

});




// =========================================
// DEFAULT ROUTE
// =========================================

app.get("/", (req, res) => {

    res.send("Express Server Running");

});




// =========================================
// SERVER
// =========================================

app.listen(3000, () => {

    console.log("Server running on port 3000");

});