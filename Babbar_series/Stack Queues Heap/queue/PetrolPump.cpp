/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   int remainingPetrol = 0;
   int finalRemainingPetrol = 0;
   int result = 0;
   for(int i=0; i<n; i++) {
       
       int petrolTillNow = remainingPetrol + p[i].petrol;
       int destiny = p[i].distance;

       if(petrolTillNow < destiny ) {
           finalRemainingPetrol += (destiny-petrolTillNow);
           remainingPetrol = 0;
           result = i+1;
           continue;
       }else {
           remainingPetrol = petrolTillNow - destiny;
       }
   }
   if(remainingPetrol >= finalRemainingPetrol) return result;
   return -1;
}

