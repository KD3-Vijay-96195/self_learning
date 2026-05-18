const express = require('express')

const result = require('../utils/result')
const pool = require('../db/pool')

const userRouter = express.Router()


//signin
userRouter.post('/signin', async(req,res) => {
    const {email, password} = req.body
    const sql = `SELECT * FROM users WHERE email = ?`
    try{
        const data = await pool.query(sql, [email])
        const dbuser = data[0][0]
        if(dbuser){
            if(password == dbuser.password){
                res.send(result.successResult(dbuser))
            }else
                res.send(result.errorResult('invalid password'))
        }
        else
            res.send(result.errorResult('Invalid Email'))

    }catch(error){
        res.send(result.errorResult(error))
    }
})


userRouter.get('/', async (req, res) => {
    const sql = `SELECT * FROM users`
    console.log(req.body);

    try {
        const data = await pool.query(sql)
        res.send(result.successResult(data[0]))
    } catch (error) {
        res.send(result.errorResult(error))
    }
})

//signup
userRouter.post('/', async (req, res) => {
    const { name, mobile, city, email, password } = req.body
    const sqlCheck = `SELECT * FROM users WHERE email = ?`
    try {
        const data = await pool.query(sqlCheck, [email])
        const result1= data[0][0]
        console.log(result1)
        if (result1) {
            res.send(result.errorResult('Email already exists'))
        }
        else {
            const sql = `INSERT INTO users(name, mobile, city, email, password) VALUES(?,?,?,?,?)`
            try {
                const data = await pool.query(sql, [name, mobile, city, email, password])
                console.log(data)
                res.send(result.successResult(data[0]))
            } catch (error) {
                res.send(result.errorResult(error))
            }
        }

    } catch (error) {
        res.send(result.errorResult(error))
    }

})

userRouter.put('/', async(req, res) => {
    const { mobile, uid } = req.body
    const sql = `UPDATE users SET mobile = ? WHERE uid = ?`
    try {
        const data = await pool.query(sql, [mobile, uid])
        res.send(result.successResult(data[0]))
    } catch (error) {
        res.send(result.errorResult(error))
    }
})

userRouter.delete('/:id', async (req, res) => {
    const sql = `DELETE FROM users WHERE uid = ?`
    try {
        const data = await pool.query(sql, [req.params.id])
        res.send(result.successResult(data[0]))
    } catch (error) {
        res.send(result.errorResult(error))
    }
})

module.exports = userRouter