#include "../couche_liaison.h"


#include <pthread.h>
;int main(int argc, char* argv[])
{

NET_DRIVERNAME *names;
NET_DRIVERLIST drivers, detected, initialised;
int i;
net_init();
net_loadconfig(NULL);
drivers = net_driverlist_create(); /* create the list for use later */
names = net_getdrivernames (net_drivers_all);
for (i = 0; names[i].name; i++) {
   printf ("%d: %s ", names[i].num, names[i].name);
   //net_driverlist_clear (drivers);
   net_driverlist_add (drivers, names[i].num);
   detected = net_detectdrivers (drivers);
   if (net_driverlist_test (detected, names[i].num)) {
      printf ("(detected) ");
      initialised = net_initdrivers (drivers);
      if (net_driverlist_test (initialised, names[i].num))
         printf ("(initialised) ");
   }
   printf ("\n");
}

printf("Deuxieme phase\n");

names=net_getdrivernames(initialised);
for(i=0;i<names[i].name;i++)
    printf("%d %s\n",names[i].num,names[i].name);
//free (names);
/* Destroy the `drivers' list, but not the other lists. */
///net_driverlist_destroy (drivers);

    pthread_t ta;
    pthread_t tb;
    printf("Main init\n");
    pthread_create(&ta,NULL,taskServer,NULL);
    pthread_create(&tb,NULL,taskClient,NULL);
    #if 1
        pthread_join(tb,NULL);
        pthread_join(ta,NULL);
    #endif // 1




}

static void taskServer(void *data){
    NET_CHANNEL *chan;
    NET_CONN *con;
    char buffer[32] = "Data to send";
    int x;
    con=net_openconn(4,"");
    if(con!=NULL) printf("OK\n");
    while(net_listen(con));
    con=net_poll_listen(con);

}
static void taskClient(void *data){
    char buffer[32] = "";
    NET_CONN *con;
    con=net_openconn(4,"");
    if(net_connect(con,"127.0.0.1",2)>0)
        printf("->TaskClent<-Connection Estabilished\n");


}


