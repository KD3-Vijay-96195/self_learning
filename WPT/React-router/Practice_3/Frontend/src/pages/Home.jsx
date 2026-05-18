import React from 'react'
import { Link, Outlet } from 'react-router'

function Home() {
    return (
        <div>
            <div>
                <Link to='/user'>User</Link>
            </div>
             <div>
                <Link to='/food'>Food</Link>
            </div>

            <Outlet />
            
        </div>
    )
}

export default Home
