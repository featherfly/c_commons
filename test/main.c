#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include <sys/time.h>
#include "os_macro.h"

typedef enum {
    /**
     * Time unit representing one thousandth of a microsecond.
     */
    NANOSECONDS,
    /**
     * Time unit representing one thousandth of a millisecond.
     */
    MICROSECONDS,
    /**
     * Time unit representing one thousandth of a second.
     */
    MILLISECONDS,
    /**
     * Time unit representing one second.
     */
    SECONDS,
    /**
     * Time unit representing sixty seconds.
     */
    MINUTES,
    /**
     * Time unit representing sixty minutes.
     */
    HOURS,
    /**
     * Time unit representing twenty four hours.
     */
    DAYS
} TimeUnit;

long getMicrotime(){
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

void delay_s(uint16_t s) {
    printf("delay_s(%u)\n", s);
    clock_t start_c = clock();
    uint32_t end = s * CLOCKS_PER_SEC;
    while(clock() - start_c < end) {
    }
}

void delay_ms(uint16_t ms) {
    printf("delay_ms(%u)\n", ms);
    clock_t start_c = clock();
    while(clock() - start_c < ms) {
    }
}

void delay_us(uint32_t us) {
    printf("delay_us(%u)\n", us);
    long start_c = getMicrotime();
    while(getMicrotime() - start_c < us) {
    }
}

void delay(uint32_t t, TimeUnit unit) {
    switch(unit) {
        case MICROSECONDS: return delay_us(t);
        case MILLISECONDS: return delay_ms(t);
        case SECONDS: return delay_s(t);
    }
}

void test(uint16_t delay_time, TimeUnit unit) {
   clock_t start_t, end_t;
   double total_t;
   uint64_t i;

   time_t start_s, end_s;
 
   start_s = time(NULL);
   start_t = clock();
   printf("程序启动，start_t = %ld\n", start_t);
    
   printf("delay(%u, %d)，start_t = %ld\n", delay_time, unit, start_t);

   delay(delay_time, unit);

   end_t = clock();
   end_s = time(NULL);
   printf("end_t = %ld\n", end_t);
   
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("CPU 占用的总时间：%f\n", total_t  );
   printf("CLOCKS_PER_SEC %d\n", CLOCKS_PER_SEC);
   printf("开始时间 %d 结束时间 %d 用时 %d\n", start_s, end_s, end_s - start_s);
}

int main(int argc, char const *argv[])
{
    SET_CONSOLE_OUTPUT_UTF8();
    #ifdef WIN32
    printf("#ifdef WIN32\n");
    #else
    printf("#ifndef WIN32\n");
    #endif        
    printf("test\n");
    test(2, SECONDS);
   printf("\n");
   test(3000, MILLISECONDS);
   printf("\n");
   test(2500 * 1000, MICROSECONDS);
   printf("\n");
    return 0;
}
