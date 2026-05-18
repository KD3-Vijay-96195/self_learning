import { createSlice } from "@reduxjs/toolkit";

const CounterSlice = createSlice({
    name: 'counter',
    initialState: {
        count: 10
    },
    reducers: {
        incrementAction: (state, action) => {
            console.log(action)
            state.count += action.payload
        },
        decrementAction: (state, action) => {
            console.log(action)
            state.count -= action.payload
        }
    }
})

export default CounterSlice.reducer
export const { incrementAction, decrementAction } = CounterSlice.actions
