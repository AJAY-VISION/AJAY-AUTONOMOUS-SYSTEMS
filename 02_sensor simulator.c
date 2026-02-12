#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_READINGS 5

int main() 
{

    float temperature[NUM_READINGS];
    float humidity[NUM_READINGS];
    float distance[NUM_READINGS];

    float temp_sum = 0, hum_sum = 0, dist_sum = 0;
    float temp_min, temp_max;
    float hum_min, hum_max;
    float dist_min, dist_max;

    srand(time(0));  // Seed random generator

    printf("---- SENSOR SIMULATOR ----\n\n");

    for(int i = 0; i < NUM_READINGS; i++)
    {
        temperature[i] = 20 + rand() % 21;   // 20-40
        humidity[i] = 30 + rand() % 61;      // 30-90
        distance[i] = 10 + rand() % 191;     // 10-200

        printf("Reading %d:\n", i+1);
        printf("Temp: %.2f C\n", temperature[i]);
        printf("Humidity: %.2f %%\n", humidity[i]);
        printf("Distance: %.2f cm\n\n", distance[i]);

        temp_sum += temperature[i];
        hum_sum += humidity[i];
        dist_sum += distance[i];

        if(i == 0)
        {
            temp_min = temp_max = temperature[i];
            hum_min = hum_max = humidity[i];
            dist_min = dist_max = distance[i];
        }

        if(temperature[i] < temp_min) temp_min = temperature[i];
        if(temperature[i] > temp_max) temp_max = temperature[i];

        if(humidity[i] < hum_min) hum_min = humidity[i];
        if(humidity[i] > hum_max) hum_max = humidity[i];

        if(distance[i] < dist_min) dist_min = distance[i];
        if(distance[i] > dist_max) dist_max = distance[i];
    }

    printf("---- RESULTS ----\n");
    printf("Temperature Avg: %.2f | Min: %.2f | Max: %.2f\n",
           temp_sum/NUM_READINGS, temp_min, temp_max);

    printf("Humidity Avg: %.2f | Min: %.2f | Max: %.2f\n",
           hum_sum/NUM_READINGS, hum_min, hum_max);

    printf("Distance Avg: %.2f | Min: %.2f | Max: %.2f\n",
           dist_sum/NUM_READINGS, dist_min, dist_max);

    return 0;
}
