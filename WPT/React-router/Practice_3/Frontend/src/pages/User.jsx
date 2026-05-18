import React, { useState } from 'react'
import { Link } from 'react-router'
import { getUser } from '../services/Userservice'

function User() {
    const [userData, setUserData] = useState([])

    const handleGetOnClick = async() => {
        try{
            const response = await getUser()
            const result = response.data
            if(result.status === 'success'){
                setUserData(result.data)
                alert('Data fetched Successfully')
            }
            else
                alert('data fetch failed')
        }catch(error){
            console.log(error)
        }
    }
  return (
    <div>
        <div>
            <button onClick={handleGetOnClick}>Get All Users</button>
        </div>
        <div>
            <Link to='/user/create'>Create User</Link>
        </div>
        <div>
            <Link to='/user/update'>Update User</Link>
        </div>
        <div>
            <Link to='/user/delete'>Delete User</Link>
        </div>
        <div>
            {userData.map(f=>(
                <div key={f.uid}>
                    <p>Name : {f.name}</p>
                    <p>Mobile : {f.mobile}</p>
                    <p>City : {f.city}</p>
                    <p>Email : {f.email}</p>
                    <hr />
                </div>
            ))}
        </div>
      
    </div>
  )
}

export default User
