#include <graphics.h>
#include <cstdio>
#include <time.h>

using namespace std;

int safedistance=650,dist_travelled=160,num=0;
int width=202,height=100,speed=100,speedo=15,level=0;
int current_distance=0,final_distance=10000,life=2;

int maxx,maxy,x1,x2,x3,x4,x1a,x2a,x3a,x4a,lane,gap,div_len,lane_dis,up_mar,menu_len,side_road,l_wid;
void Initialize()
{
 initwindow(1780,780,"car_game",0,0,false);
}


struct node
{
    int x,y;
    node *next;
}*first,*last,*p;

void new_node()
{
    p=new node;
    p->next=NULL;
    last->next=p;
    last=p;
    srand (time(NULL));
    int lane=rand()%3;
    p->y=135+(lane*230);
    p->x=maxx-width;
}




void car()
{
    if(lane==1)readimagefile("mycar.jpg",up_mar,135,282,235);
    else if(lane==2)readimagefile("mycar.jpg",up_mar,365,282,465);
    else readimagefile("mycar.jpg",up_mar,595,282,695);
}
void display(int x,int y, char text[],int size=1,int box=BLUE,int txt=WHITE)
{
    setbkcolor(box);
    setcolor(txt);
    settextstyle(GOTHIC_FONT,HORIZ_DIR,size);
    outtextxy(x,y,text);
    setbkcolor(BLACK);
}
void upper_boundary()
{
    setfillstyle(SOLID_FILL, BLUE);
    bar(0, 0, getmaxx(), 50);
}

void update_lives(int value)
{
    char arr[1];
    sprintf(arr,"%d",value);
    display(5,5,"Lives : ");
    display(100,5,arr);
}


void update_distance(int value)
{
    char arr[4];
    sprintf(arr,"%d",value);
    display(680,5,"Distance Remaining : ");
    display(970,5,arr);
}

void menu()
{
    display(5,5,"Lives : ");
    display(170,5,"Pause : P");
    display(340,5,"Restart : R");
    display(510,5,"Quit : Q");
    display(680,5,"Distance Remaining : ");
}
void road_bound()
{
    setfillstyle(SOLID_FILL,WHITE);
    bar(0,50,getmaxx(),up_mar);
    bar(0,getmaxy()-30,getmaxx(),getmaxy());
}
void remove_car()
{
    setfillstyle(SOLID_FILL,BLACK);
    if(lane==1)bar(79,134,283,236);
    else if(lane==2)bar(79,364,283,466);
    else bar(79,594,283,696);
}

void init_div()
{
    setfillstyle(SOLID_FILL,WHITE);
    bar(x1,lane_dis+up_mar,x1a,lane_dis+l_wid+81);  bar(x1,lane_dis+up_mar+lane_dis+l_wid,x1a,lane_dis+l_wid+81+lane_dis+l_wid);
    bar(x2,lane_dis+up_mar,x2a,lane_dis+l_wid+81);  bar(x2,lane_dis+up_mar+lane_dis+l_wid,x2a,lane_dis+l_wid+81+lane_dis+l_wid);
    bar(x3,lane_dis+up_mar,x3a,lane_dis+l_wid+81);  bar(x3,lane_dis+up_mar+lane_dis+l_wid,x3a,lane_dis+l_wid+81+lane_dis+l_wid);
    bar(x4,lane_dis+up_mar,x4a,lane_dis+l_wid+81);  bar(x4,lane_dis+up_mar+lane_dis+l_wid,x4a,lane_dis+l_wid+81+lane_dis+l_wid);

}
void divider()
{

    setfillstyle(1,BLACK);
    bar(x1a,lane_dis+up_mar,x1a+speed,lane_dis+l_wid+up_mar+1);    bar(x1a,lane_dis+up_mar+lane_dis+l_wid,x1a+speed,lane_dis+l_wid+up_mar+lane_dis+l_wid+1);
    bar(x2a,lane_dis+up_mar,x2a+speed,lane_dis+l_wid+up_mar+1);    bar(x2a,lane_dis+up_mar+lane_dis+l_wid,x2a+speed,lane_dis+l_wid+up_mar+lane_dis+l_wid+1);
    bar(x3a,lane_dis+up_mar,x3a+speed,lane_dis+l_wid+up_mar+1);    bar(x3a,lane_dis+up_mar+lane_dis+l_wid,x3a+speed,lane_dis+l_wid+up_mar+lane_dis+l_wid+1);
    bar(x4a,lane_dis+up_mar,x4a+speed,lane_dis+l_wid+up_mar+1);    bar(x4a,lane_dis+up_mar+lane_dis+l_wid,x4a+speed,lane_dis+l_wid+up_mar+lane_dis+l_wid+1);

    x1-=speed;x2-=speed;x3-=speed;x4-=speed;x1a-=speed;x2a-=speed;x3a-=speed;x4a-=speed;

    setfillstyle(1,WHITE);
    bar(x1,lane_dis+up_mar,x1+speed,lane_dis+l_wid+up_mar+1);  bar(x1,lane_dis+up_mar+lane_dis+l_wid,x1+speed,lane_dis+l_wid+up_mar+lane_dis+l_wid+1);
    bar(x2,lane_dis+up_mar,x2+speed,lane_dis+l_wid+up_mar+1);  bar(x2,lane_dis+up_mar+lane_dis+l_wid,x2+speed,lane_dis+l_wid+up_mar+lane_dis+l_wid+1);
    bar(x3,lane_dis+up_mar,x3+speed,lane_dis+l_wid+up_mar+1);  bar(x3,lane_dis+up_mar+lane_dis+l_wid,x3+speed,lane_dis+l_wid+up_mar+lane_dis+l_wid+1);
    bar(x4,lane_dis+up_mar,x4+speed,lane_dis+l_wid+up_mar+1);  bar(x4,lane_dis+up_mar+lane_dis+l_wid,x4+speed,lane_dis+l_wid+up_mar+lane_dis+l_wid+1);




    delay(1);

    if(x1<0)x1=getmaxx();if(x1a<0)x1a=getmaxx();
    if(x2<0)x2=getmaxx();if(x2a<0)x2a=getmaxx();
    if(x3<0)x3=getmaxx();if(x3a<0)x3a=getmaxx();
    if(x4<0)x4=getmaxx();if(x4a<0)x4a=getmaxx();

}
void initial_values()
{
   maxx=getmaxx(),maxy=getmaxy(),lane=2,menu_len=50,side_road=30,up_mar=menu_len+side_road;
   gap=195,div_len=250,lane_dis=210,l_wid=20;
   x1=gap,x1a=x1+div_len,x2=x1a+gap,x2a=x2+div_len,x3=x2a+gap,x3a=x3+div_len,x4=x3a+gap,x4a=x4+div_len;

    safedistance-=level;
    first=new node;
    first->x=maxx-width;
    first->y=135;
    last=first;
    first->next=NULL;
}

void end_screen()
{
    delay(800);
    cleardevice();
    //update_score(value);
    display(80,180,"Thank you for playing",6);
    display(100,270,"Press any key to exit....",4);
    getch();
    exit(0);
   // display(180,350,"Press 'R' to play again",1,YELLOW,BLACK);
}

void collision()
{
    bool flag=false;
    if(first->x<=282&&first->x+width>=up_mar)
    {
        if(lane==1&&first->y==135)flag=true;
        if(lane==2&&first->y==365)flag=true;
        if(lane==3&&first->y==595)flag=true;
    }
    if(flag)
    {
        setfillstyle(1,BLACK);
        bar(first->x,first->y,first->x+width+11,first->y+height+1);
        setfillstyle(1,WHITE);
        car();
        life--;
        p=first;
        first=first->next;
        delete p;
        if(life<0)
            end_screen();
        update_lives(life);
    }
}


void welcome_screen()
{
    display(70,140,"WELCOME TO CAR",4);
    display(80,210,"Press any key to begin...",3);
    display(80,310,"Credits :");
    display(200,310,"Safal Pandita",1,YELLOW,BLACK);
    display(200,340,"Pulkit Kariryaa",1,YELLOW,BLACK);
    display(200,370,"Aditya Kathuria",1,YELLOW,BLACK);

    getch();
    cleardevice();
}



int main()
{



   Initialize();
   welcome_screen();

   initial_values();
   upper_boundary();
   menu();
   car();
   update_lives(3);
   road_bound();
   init_div();

   while(current_distance<final_distance)
   {


        update_distance((final_distance-current_distance)/1000);


       if(dist_travelled>=safedistance)
        {
            dist_travelled=0;
            new_node();
        }

        setfillstyle(1,BLACK);
        for(p=first;p->next!=NULL;p=p->next)
        {
            bar(p->x+width,p->y,p->x+width+speedo+1,p->y+height+1);
            readimagefile("carr.jpg",p->x,p->y,p->x+width,p->y+height);
            p->x-=speedo;


        if(first->x<=-width-4)
        {

            p=first;
            first=first->next;
            delete p;
        }
        }
        setfillstyle(1,WHITE);
        dist_travelled+=speedo;
        current_distance+=speed;



        collision();




       divider();
       if(kbhit())
       {
           char ch=getch();
           if(ch=='w')
           {
               if(lane==1)lane=1;
               else
                {
                   remove_car();
                   lane--;
                }
               car();
           }
           else if(ch=='s')
           {
               if(lane==3)lane=3;
               else
               {
                   remove_car();
                   lane++;
               }
               car();
           }
       }
   }


    setfillstyle(1,BLACK);
   for(p=first;p->next!=NULL;p=p->next)
    {

        bar(p->x,p->y,p->x+width+speedo+1,p->y+height+1);
    }
    setfillstyle(1,WHITE);



   for(int x=maxx-80;x>maxx/2;x-=speed)
   {

       divider();
       if(kbhit())
       {
           char ch=getch();
           if(ch=='w')
           {
               if(lane==1)lane=1;
               else
                {
                   remove_car();
                   lane--;
                }
               car();
           }
           else if(ch=='s')
           {
               if(lane==3)lane=3;
               else
               {
                   remove_car();
                   lane++;
               }
               car();
           }
       }

       readimagefile("check.jpg",x,81,x+80,maxy-30);
       setfillstyle(1,BLACK);
       bar(x+80,81,maxx,maxy-30);
       setfillstyle(1,WHITE);

   }

    int y;


    if(lane==1)y=135;
    else if(lane==2)y=365;
    else y=595;


    setfillstyle(1,BLACK);
    for(int x=up_mar;x<maxx;x+=speed)
    {

        bar(x-speed-4,y,x+1,y+height+1);
        readimagefile("carr.jpg",x,y,x+width,y+height);
        delay(12);
        x+=speedo;
    }
    setfillstyle(1,WHITE);
    end_screen();

   getch();
}
