import React from "react";
import config from './../utils/config';
import axios from "axios";

export async function getUser(){
    try{
        const URL = config.BASE_URL+'/user/'
        return await axios.get(URL)
    }catch(error){
        console.log(error);
    }
}

export async function postUser(userData){
    try{
        const URL = config.BASE_URL+'/user/'
        return await axios.post(URL, userData)
    }catch(error){
        console.log(error);
    }
}

export async function putUser(userData){
    try{
        const URL = config.BASE_URL+'/user/'
        return await axios.put(URL, userData)
    }catch(error){
        console.log(error);
    }
}

export async function deleteUser(id){
    try{
        const URL = config.BASE_URL+'/user/'+id
        return await axios.delete(URL)
    }catch(error){
        console.log(error);
    }
}