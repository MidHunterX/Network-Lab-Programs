/* Stop and wait - Flow control
--------------------------------
* Stop and Wait for ARQ mainly implements the Sliding Window Protocol concept with Window Size = 1
* It offers error and flows control
* It is used in Data Link and Transport Layers
*/
/* ALGORITHM
* Send a frame from sender to reciever
* If error happens while sending frame, retry again
* Receive the frame at the receiver side
* Send an ACK acknowledgement for the frame back to the server
* If error happens while sending ACK, retry again
* Do above steps until all frames are sent
*/
#include<stdio.h>
#include<stdlib.h>
int err,i,n;
char s[8]="Sender:",r[8]="Recevr:",stat;
int send(){
    // i-1 cuz, sender gets prev iteration of recv
    if(stat=='r')printf("\n%s Received ACK %d",s,i-1); err = rand()%4;
    //crossing out status checking while resending
    if(err==0)send(printf("\n%s Error while sending frame...\n%s Resending frame...",s,s,stat='x'));
    else printf("\n%s Frame %d sent\n",s,i,stat='s');
}
int recv(){
    if(stat=='s')printf("\n%s Received Frame %d",r,i); err = rand()%4;
    if(err==0)recv(printf("\n%s Error while sending ACK...\n%s Resending ACK...",r,r,stat='x'));
    else printf("\n%s ACK %d sent\n",r,i,stat='r');
}
void main(){
    scanf("%d",&n,printf("Enter no. of frames: "));
    for(i=1;i<=n;i++)recv(send());
}
