#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TARGET_X 0
#define TARGET_Y 0
#define TIME_SECONDS 3600
#define NUM_TRIALS 100000


int randm(int seed)
{
 int i, stime;
  long ltime;

  /* get the current calendar time */
  ltime = time(NULL);
  stime = (unsigned) ltime/2;
  //srand(stime);
  int result = rand() % seed;
 return result;
}

int walk(int target_x, int target_y, int time_length)
{
	int move_options[5][2] = {
    {0,0},
    {0,1},
    {0,-1},
    {1,0},
    {-1,0} };
time_t t;
    int delta[2];
	int current_x = 0, current_y = 0, dx,dy;
	   		//printf("(%d,", current_x);
	//	printf("%d)   ",current_y);
	for ( int seconds = 1; seconds <= time_length +1; seconds++ ) {
	//	printf(" t:%ds ",seconds);
		//printf("(%d,", current_x);
		//printf("%d)   ",current_y);

   		

   		int row = randm(5);
   	//	printf(" r: %d ",row);			

   		dx = move_options[row][0];
   		dy = move_options[row][1];
   		//printf("dx:%d ", dx);
		//printf("dy: %d, ",dy);
   		if (abs(dx + current_x) > 2 ){
   			dx = 0;
   			dy = 0;	
   		}
   		if (abs(dy + current_y) > 2 ){
   			dx = 0;
   			dy = 0;	
   		}
   		current_x = current_x + dx;
   		current_y = current_y + dy;
   	//	printf("(%d,", current_x);
	//	printf("%d)   ",current_y);
   		
	}
	if ((abs(current_x) == 2) || (abs(current_y) == 2))
	//if ((target_x == current_x) && (target_y == current_y))
   		{	return 1;}
	else return 0;


}

float calc_probability (int x,int y,int time,int trial_max)
{
	int event_count = 0;
	float event_probability;
	for ( int trial = 1; trial <= trial_max; trial++ ) {
	//		printf("\ntrial:%d ", trial);

   			event_count = event_count + walk(x,y,time);
   	//		printf("\n event count: %d ",event_count);

   		}
   	event_probability = (float)event_count/(float)trial_max;
   	   			printf("\n event count: %d ",event_count);

   	printf(" Trial Max: %d ",trial_max );
   	printf(" probability: %.3f ",event_probability);

   	return event_probability;

}

int main()
{
	//final x, final y, final time, number of trials
	float probability = calc_probability(TARGET_X,TARGET_Y,TIME_SECONDS,NUM_TRIALS);

   //	printf("\n\n\nProbability: %.3f\n", probability);

	
   	int random = randm(5);
   	printf("\nRandomn test: %d\n",random);

   	return 0;	
}




