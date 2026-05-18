import React, { useState } from 'react'
import { putUser } from '../../services/Userservice'

function Put() {
  const [mobile, setMobile] = useState('')
  const [uid, setUid] = useState('')

  const handlePutOnClick = async() => {
    try{
      const body = {mobile, uid}
      const response = await putUser(body)
      const result = response.data
      if(result.status === 'success'){
        alert('user updated successfully')
      }
      else{
        alert('update failed')
      }
    }catch(error){
      console.log(error)
    }
  }
  return (
    <div>
      <table>
        <tbody>
          <tr>
            <td>
              <label htmlFor="">uid: </label>
            </td>
            <td>
              <input type="text" placeholder='enter user id' onChange={e => setUid(e.target.value)} />
            </td>
          </tr>
          <tr>
            <td>
              <label htmlFor="">Mobile: </label>
            </td>
            <td>
              <input type="tel" placeholder='enter mobile' onChange={e => setMobile(e.target.value)} />
            </td>
          </tr>
        </tbody>
      </table>
      <div>
        <button onClick={handlePutOnClick}>Submit</button>
      </div>
    </div>
  )
}

export default Put
