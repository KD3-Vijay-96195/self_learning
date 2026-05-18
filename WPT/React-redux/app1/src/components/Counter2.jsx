import { useDispatch, useSelector } from 'react-redux'
import { decrementAction } from '../slices/CounterSlice'

function Counter2() {
    const count = useSelector(store => store.CounterSlice.count)
    const dispatch = useDispatch()
    return (
        <div>
            <h2>Counter 2</h2>
            <h3>Count :{count} </h3>
            <button onClick={() => { dispatch(decrementAction(5)) }}>decrement</button>
        </div>
    )
}

export default Counter2
