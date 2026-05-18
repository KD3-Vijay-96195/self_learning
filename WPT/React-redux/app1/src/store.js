import { configureStore } from '@reduxjs/toolkit'
import CounterSlice from './slices/CounterSlice';

const store = configureStore({
    reducer: {
        CounterSlice,
    }
})

export default store