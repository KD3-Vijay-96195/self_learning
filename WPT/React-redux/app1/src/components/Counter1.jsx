import { useDispatch, useSelector } from "react-redux"
import { incrementAction } from "../slices/CounterSlice"

function Counter1() {
    const count = useSelector(store => store.CounterSlice.count)
    const dispatch = useDispatch()
    return (
        <div>
            <h2>Counter 1</h2>
            <h3>Count : {count}</h3>
            <button onClick={() => { dispatch(incrementAction(2)) }}>increment</button>
        </div>
    )
}

export default Counter1
