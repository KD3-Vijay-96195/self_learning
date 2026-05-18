import React, { useState } from 'react'
import config from '../../utils/config'
import { postUser } from '../../services/Userservice'

function Post() {
  const [name, setName] = useState('')
  const [mobile, setMobile] = useState('')
  const [city, setCity] = useState('')
  const [email, setEmail] = useState('')

  const handlePostOnClick = async() => {
    try{
      const body = {name, mobile, city, email}
      const response = await postUser(body)
      const result = response.data
      if(result.status === 'success'){
        alert('User created Successfully')
      }
      else{
        alert('User Creation Failed')
      }
    }catch(error){
      console.log(error);
    }
  }

  return (
    <div>
      <table>
        <tbody>
          <tr>
            <td>
              <label htmlFor="">Name: </label>
            </td>
            <td>
              <input type="text" placeholder='enter name' onChange={e=>setName(e.target.value)} />
            </td>
          </tr>
          <tr>
            <td>
              <label htmlFor="">Mobile: </label>
            </td>
            <td>
              <input type="tel" placeholder='enter mobile' onChange={e=>setMobile(e.target.value)} />
            </td>
          </tr>
          <tr>
            <td>
              <label htmlFor="">City: </label>
            </td>
            <td>
              <input type="text" placeholder='enter city' onChange={e=>setCity(e.target.value)} />
            </td>
          </tr>
          <tr>
            <td>
              <label htmlFor="">Email: </label>
            </td>
            <td>
              <input type="email" placeholder='enter email' onChange={e=>setEmail(e.target.value)} />
            </td>
          </tr>
        </tbody>
      </table>
      <div>
        <button onClick={handlePostOnClick}>Submit</button>
      </div>

    </div>
  )
}

export default Post
