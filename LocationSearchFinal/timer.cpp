//----------------------------------------------
// Purpose: Implementation of Timer class.
// Author:  John Gauch
//----------------------------------------------

#include "timer.h"

//----------------------------------------------
Timer::Timer()
{
   start_flag = false;
   end_flag = false;
}

//----------------------------------------------
void Timer::start_timer()
{
   start_flag = true;
   start_clock = clock();
   gettimeofday(&start_timeval, NULL);
}

//----------------------------------------------
void Timer::end_timer()
{
   end_flag = true;
   end_clock = clock();
   gettimeofday(&end_timeval, NULL);
}

//----------------------------------------------
float Timer::elapsed_cpu()
{
   if (start_flag && end_flag)
      return float(end_clock-start_clock)/float(CLOCKS_PER_SEC);
   else
      return 0;
}

//----------------------------------------------
float Timer::elapsed_time()
{
   if (start_flag && end_flag)
      return (end_timeval.tv_sec - start_timeval.tv_sec) + 
             (end_timeval.tv_usec - start_timeval.tv_usec) / 1000000.0;
   else
      return 0;
}

//----------------------------------------------
#ifdef TIMER_MAIN
int main()
{
   Timer t;
   t.start_timer();

   // Do some silly calculations
   double total = 0;
   for (int i=0; i<10000; i++)
   {
      for (int j=0; j<10000; j++)
         total += sqrt(i+j);
      cout << total << endl;
   }

   t.end_timer();
   cout << "cpu time:     " << t.elapsed_cpu() << endl;
   cout << "elapsed time: " << t.elapsed_time() << endl;
}
#endif