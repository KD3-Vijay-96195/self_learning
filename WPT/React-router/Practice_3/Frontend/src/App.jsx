import React from 'react'
import { Route, Routes } from 'react-router'
import Home from './pages/Home'
import User from './pages/User'
import Post from './components/user/Post';
import Put from './components/user/Put';
import Delete from './components/user/Delete';

function App() {
  return (
    <div>
      <Routes>
        <Route path='/' element={<Home />} />
        <Route path='/user' element={<User />} />
        <Route path='/user/create' element={<Post />} />
        <Route path='/user/update' element={<Put />} />
        <Route path='/user/delete' element={<Delete />} />

      </Routes>

    </div>
  )
}

export default App
