#include "../include/thread_pool.hpp"


thread_pool::thread_pool(int number_of_threads):current_number_of_threads(number_of_threads){

    //what to do here if number_of_threads is incorrect value?
    if (!(number_of_threads<=MAX_NUMBER_OF_THREADS || number_of_threads>0)){
        //handle_error
    }

    threads.resize(current_number_of_threads);

    for (int i = 0;i<current_number_of_threads;i++)
        empty_threads.push_back(i); //at start all threads are empty

}