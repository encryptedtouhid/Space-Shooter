#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>

int count=0;

class Graphics
{
private :

	int driver;
	int mode;

public :

	void loadGraphics()
	{
		driver=DETECT;
		initgraph(&driver,&mode,"c:\\tc\\bgi");
	}

};




class murgi

{
private :

	int x,y,radius,color;

public :

	  murgi(int xx=0,int yy=0,int r=0,int c=WHITE)
	{
		x=xx;
		y=yy;
		radius=r;
		color=c;
	}
	void draw()
	{
		setbkcolor(GREEN);
		setcolor(color);
		circle(x,y,radius);

	}
	void left()
	{
		x=x+1;
	}
	void down()
	{
		y=y+20;
	}

};
class Gun

{
private :

	int x,y,radius,color;

public :

	  Gun(int xx=0,int yy=0,int r=0,int c=WHITE)
	{
		x=xx;
		y=yy;
		radius=r;
		color=c;
	}
	void draw()
	{
		setbkcolor(GREEN);
		setcolor(color);
		circle(x,y,radius);

	}
	void left()
	{
		if(x!=30)
		x=x-20;
	}
	void right()
	{
		if(x!=590)
		x=x+20;
	}

};

class Fire

{
private :

	int x,y,radius,color;

public :

	  Fire(int xx=0,int yy=0,int r=0,int c=WHITE)
	{
		x=xx;
		y=yy;
		radius=r;
		color=c;
	}
	void draw()
	{
		setbkcolor(GREEN);
		setcolor(color);
		circle(x,y,radius);

	}
	void up()
	{
		y=y-20;
	}

};

class movement
{
	 murgi sd;
	 Gun gd;

public :
	  movement()
	{
		sd = murgi(30,30,30,BLUE);
	}
	void default_chicken_positon(){sd = murgi(30,30,30,BLUE);}
	void startmovement()
	{
			cleardevice();
			sd.draw();
			sd.left();
			gd.draw();
	}
	void murgi_down(){
	int i=0;
	while(i<20){
	delay(150);
	cleardevice();
	sd.draw();
	sd.down();
	i++;}
	}
	void place_gun(){gd = Gun(30,450,30,BLUE);}
	void gun_left(){gd.left();}
	void gun_right(){gd.right();}

};


class Game{
public:
char control;
movement anim;
void startGame(){
anim.place_gun();
while(1){

	if(count==550){anim.default_chicken_positon();count=0;}
	anim.startmovement();
	delay(8);
	if(kbhit()){/*anim.murgi_down();*/
	control=getch();
	if(control=='8')break;
	else if(control=='4')anim.gun_left();
	else if(control=='6')anim.gun_right();
	}
	count++;
	} }
};

int main()
{

	Graphics g;
	g.loadGraphics();

	Game G1;
	G1.startGame();

	getch();

	return 0;
}
