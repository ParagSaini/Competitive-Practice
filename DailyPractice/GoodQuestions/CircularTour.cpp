// link: https://practice.geeksforgeeks.org/problems/circular-tour/1#
class petrolPump{
    public:
    int petrol, distance;
    petrolPump(int p, int d) { petrol = p; distance = d;}
};

int tour(petrolPump p[],int n)
{
   int remainingPetrol = 0;
   int finalRemainingPetrol = 0;
   int result = 0;
   for(int i=0; i<n; i++) {
       int curPetrol = remainingPetrol + p[i].petrol;
       int destiny = p[i].distance;
       if(curPetrol < destiny ) {
           finalRemainingPetrol += (destiny-curPetrol);
           remainingPetrol = 0;
           result = i+1;
       }else {
           remainingPetrol = curPetrol - destiny;
       }
   }
   if(remainingPetrol >= finalRemainingPetrol) return result;
   return -1;
}