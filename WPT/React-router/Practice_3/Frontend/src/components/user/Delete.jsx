import React, { useState } from 'react'
import { deleteUser } from '../../services/Userservice'

function Delete() {
  const [uid, setUid] = useState('')

  const handleDeleteOnClick = async() => {
    try{
      const response = await deleteUser(uid)
      const result = response.data
      if(result.status === 'success'){
        alert('user deleted successfully')
      }
      else{
        alert('user deletion failed')
      }

    }catch(error){
      console.log(error)
    }
  }
  return (
    <div>
      <div>
        <label>UID : </label>
        <input type="text" placeholder='enter user id' onChange={e=>setUid(e.target.value)} />
      </div>
      <div>
        <button onClick={handleDeleteOnClick}>Submit</button>
      </div>
      
    </div>
  )
}

export default Delete
