/***
	Author: MD Sdarul Islam Toaha

	Institute: United IOnternational university

***/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"iGraphics.h"

#define JUMPLIMIT 150
#define FLYLIIMIT 600
#define screenWidth 1200
#define screenHeight 700
#define UpperBackgroundSpeed 60
#define LowerBackgroundSpeed 100
#define BallNumber 2

int score=0;
char SCORE;

int TEM=0;

//
int Queue[500];
int start, end;

void Enqueue(int v)
{
  
        Queue[end++] = v;
}
int Dequeue()
{
  
        return Queue[start++];
}
void print()
{
    int i;
    for(i=start;i<=end;i++)
    {
        printf("%d ", Queue[i]);
    }
    printf("\n");
}

//


int i,p=0,flycount=0;
int vX , vY;
int coverX = 0 ,coverY = 0;
int bcX = 0 , bcY = 0;
int ironManCordinateX = 150 , ironManCordinateY = 0,ironManCordinateJump = 0,ironManCordinatefly = 20,ironManCordinateFire = 0;
int ironManIndex = 0, PowerIndex=0, flyIndex = 0, FireIndex = 0, backgroundIndex = 0,BallIndex =0;
int buX =0,blX=0;
int standCounter=0;
int buttonX=0,buttonY =0;

bool ScorePage=false;
bool turn=true;
bool turnF=false;
bool turnB =false;
bool sound =true;
bool BallShow = true;
bool standPosition = true;
bool power = false;
bool fire = false;
bool jump = false;
bool jumpUp = false;
bool fly = false;
bool flyUp = false;
bool flyDown = false;
bool coverPage = true;
bool gamePage = false;
bool InfoPage = false;
bool exitPage =false;
bool scorePage =false;
bool settingsPage =false;
bool FLYPOWER =false;
bool FLYFIRE = false;
bool JUMPPOWER = false;
bool JUMPFIRE = false;

char UpperBackgroundImg[12][20]={"Background\\a.bmp","Background\\b.bmp","Background\\c.bmp","Background\\d.bmp","Background\\e.bmp","Background\\f.bmp","Background\\g.bmp","Background\\h.bmp","Background\\i.bmp","Background\\j.bmp","Background\\k.bmp","Background\\l.bmp"};
char LowerBackgroundImg [12][20]={"Background\\1.bmp","Background\\2.bmp","Background\\3.bmp","Background\\4.bmp","Background\\5.bmp","Background\\6.bmp","Background\\7.bmp","Background\\8.bmp","Background\\9.bmp","Background\\10.bmp","Background\\11.bmp","Background\\12.bmp"};
char ironMan[9][15]={"IronMan\\1.bmp","IronMan\\2.bmp","IronMan\\3.bmp","IronMan\\4.bmp","IronMan\\5.bmp","IronMan\\6.bmp","IronMan\\7.bmp","IronMan\\8.bmp","IronMan\\9.bmp"};
char ironManJ[2][15]={"IronMan\\j1.bmp","IronMan\\j2.bmp"};
char ironManStand[15]="IronMan\\1.bmp";
char ironManfly[3][25]={"IronMan\\FL1.bmp","IronMan\\FL2.bmp","IronMan\\FL3.bmp"};
char ironManFire[20]="IronMan\\IFire.bmp";
char ironManPower[20]="IronMan\\IPower.bmp";
char Fire[15]="IronMan\\F3.bmp";
char Power[15]="IronMan\\P3.bmp";
char ballE[2][23]={"obstacle\\EN1.bmp","obstacle\\EN2.bmp"};


void music()
{
	if(sound)
	{
		if (coverPage)
		{
		  PlaySound("Sound\\1.wav",NULL,SND_ASYNC);
		}
	}
}


void UBackgroundRendering()
{
	
	iShowBMP(buX,bcY,UpperBackgroundImg[backgroundIndex]);

}
void LBackgroundRendering()
{
	iShowBMP(blX,bcY,LowerBackgroundImg[backgroundIndex]);
}


void ironManMovement()
{
	/*if(JUMPPOWER)
	{
				iShowBMP2(ironManCordinateX,ironManCordinateY+ironManCordinateJump,ironManJ[0],0);
				iShowBMP2(ironManCordinateX+ironManCordinateFire,ironManCordinateY+ironManCordinateJump,Power,0);
	}
	else if (JUMPFIRE)
	{
			    iShowBMP2(ironManCordinateX,ironManCordinateY+ironManCordinateJump,ironManJ[0],0);
				iShowBMP2(ironManCordinateX+ironManCordinateFire,ironManCordinateY+ironManCordinateJump,Fire,0);
	}			
	else if(FLYPOWER)
	{					
				iShowBMP2(ironManCordinateX,ironManCordinateY+ironManCordinatefly,ironManfly[1],0);
				iShowBMP2(ironManCordinateX+ironManCordinateFire,ironManCordinateY,Power,0);
				power = false ;
				JUMPPOWER = false;
	}
	else if (FLYFIRE)
	{
		 iShowBMP2(ironManCordinateX,ironManCordinateY+ironManCordinatefly,ironManfly[1],0);
		 iShowBMP2(ironManCordinateX+ironManCordinateFire,ironManCordinateY,Fire,0);
		 fire = false ;
		 JUMPFIRE = false ;
	}
	*/

	 if(power)
	{

		iShowBMP2(ironManCordinateX,ironManCordinateY,ironManPower,0);
		iShowBMP2(ironManCordinateX+ironManCordinateFire,ironManCordinateY+20,Power,0);

		//iText(950,600, "PRESS HOME BUTTON TO GO-BACK",GLUT_BITMAP_8_BY_13);
					
	
	}

	else if(fire)
	{
		iShowBMP2(ironManCordinateX,ironManCordinateY,ironManFire,0);
		iShowBMP2(ironManCordinateX+ironManCordinateFire,ironManCordinateY+50,Fire,0);

	}
	else if(fly)
		{
						standCounter++;
						if(standCounter>=15)
						{
							BallShow =true;	
							standCounter=0;
						}
			if(flyUp)
			{
					iShowBMP2(ironManCordinateX,ironManCordinateY+ironManCordinatefly,ironManfly[1],0);
			}
		}
	
	else if (jump)
			{
				if (jumpUp)
				{
							iShowBMP2(ironManCordinateX,ironManCordinateY+ironManCordinateJump,ironManJ[0],0);
				}
				else
				{
							iShowBMP2(ironManCordinateX,ironManCordinateY+ironManCordinateJump,ironManJ[1],0);
				}
			}
		else
			{
				if(!standPosition)
				{
						
						iShowBMP2(ironManCordinateX,ironManCordinateY,ironMan[ironManIndex],0);
						standCounter++;
						if(standCounter>=15)
						{
							BallShow =true;	

						}
						if(standCounter>=15)
						{
							standCounter = 0;
							ironManIndex = 1;
							standPosition=true;
						}
					
				}
				else
				{  
						
						iShowBMP2(ironManCordinateX,ironManCordinateY,ironManStand,0);
				}
			}
}

void EnemyMovement()
{
	if(BallShow){
	iShowBMP2(vX,vY,ballE[0],0);
	}
}

void iDraw()
{
	iClear();

	if(coverPage)
	{
		iShowBMP(bcX,bcY,"Background//coverPage.bmp");
		iShowBMP2(buttonX+100,buttonY+500,"Background//play.bmp",0);
		iShowBMP2(buttonX+100,buttonY+400,"Background//option.bmp",0);
		iShowBMP2(buttonX+100,buttonY+300,"Background//settings.bmp",0);
		iShowBMP2(buttonX+100,buttonY+200,"Background//quit.bmp",0);


	}
	else if (gamePage)
	{
		UBackgroundRendering();
		LBackgroundRendering();
		
		ironManMovement();
		EnemyMovement();
		iText(950,680, "PRESS HOME BUTTON TO GO-BACK",GLUT_BITMAP_8_BY_13);

	}
	else if (InfoPage)
	{
		iShowBMP(coverX,coverY,"Background//Instructionpage.bmp");
		iText(950,680, "PRESS HOME BUTTON TO GO-BACK",GLUT_BITMAP_8_BY_13);
	}
	else if (scorePage)
	{
		iShowBMP(coverX,coverY,"scorepage");
	}
	
	else if(settingsPage)
	{
		iShowBMP(coverX,coverY,"Background//Settingspage.bmp");
		iText(890,590, "PRESS HOME BUTTON TO GO-BACK",GLUT_BITMAP_8_BY_13);
	
	}
	else if(ScorePage)
	{
		iShowBMP(coverX,coverY,"Background//GAMEO.bmp");
		//S=atoi(SCORE);
		//iText(890,590, SCORE ,GLUT_BITMAP_8_BY_13);
		if(TEM== 0)
		{
			TEM=1;
			Enqueue(score);
		}
	}
	else if (exitPage)
	{
		exit(1);
	}
}

void iMouseMove(int mx,int my)
{

}

void iMouse(int button,int state,int mx,int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//("%d %d \n",mx,my);
		
		if((mx >=100 && mx <=300 )&&( my >= 500 && my <=550))
		{
			coverPage  = false ;
			gamePage   = true ;
			InfoPage   = false ;
			settingsPage = false ; 
			exitPage = false ;
		}
		else if ((mx >=100 && mx <=300 )&&( my >= 400 && my <=450))
		{
		
			coverPage  = false ;
			gamePage   = false ;
			InfoPage   = true ;
			settingsPage = false ; 
			exitPage = false ;

		}
		else if  ((mx >=100 && mx <=300 )&&( my >= 300 && my <=350))
		{
			coverPage  = false ;
			gamePage   = false ;
			InfoPage   = false ;
			settingsPage = true ; 
			exitPage = false ;
				
		}
		else if ((mx >=100 && mx <=300 )&&( my >= 200 && my <=250))
		{
			coverPage  = false ;
			gamePage   = false ;
			InfoPage   = false ;
			settingsPage = false ; 
			exitPage = true ;
		}
		else if ((mx >=900 && mx <=1000 )&&( my >= 620 && my <=640))
		{
			sound =true;
		}
		else if ((mx >=1040 && mx <=1200 )&&( my >= 620 && my <=640))
		{
			sound =false;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

void iPassiveMouseMove(int mx,int my)
{
   
}

void iKeyboard(unsigned char key)
{
	
   if(key == 'j')
	{
		if(!jump)
		{
			jump =true;
			jumpUp = true;
		}

	}
	else if(key == 'p')
	{
		power = true;	
		JUMPPOWER =true;
		FLYPOWER = true;
	}

	else if(key == 'f')
	{
		fire = true;
		JUMPFIRE = true;
		FLYFIRE = true;

	}
	else if(key == 's')
	{
		print();

	}
	
}

void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_UP)
	{
		if(!fly)
		{
		fly = true;  
		flyUp = true ;
		}
	}

	else if(key == GLUT_KEY_LEFT)
	{
		
	}
	else if(key == GLUT_KEY_RIGHT)
	{
		
		 ironManIndex++;
		 if(ironManIndex>=9 )
		 {
			 ironManIndex=1;
		 }
		backgroundIndex ++;
		if(backgroundIndex >= 11)
		{ backgroundIndex=0;}
			
		standPosition = false;
		
	}
	else if(key == GLUT_KEY_DOWN)
	{
		
			flyDown=true;
	    	ironManCordinatefly -=20;
		
	}
	else if(key == GLUT_KEY_HOME)
	{
		coverPage  = true ;
		gamePage   = false ;
		InfoPage   = false ;
		settingsPage = false ; 
		exitPage = false ;
	}

}

void change1()
{
	

	if(score==30)
					{
						ScorePage=true;
						coverPage  = false ;
						gamePage   = false ;
						InfoPage   = false ;
						settingsPage = false ; 
						exitPage = false ;
					}
	if(fire)
	{
			ironManCordinateFire+=110;
			if(ironManCordinateFire >= vX-20)
				{
					fire = false;
					ironManCordinateFire=0;
					BallShow =false ;
					vX =screenWidth;
					score=score+10;
					SCORE=score;
	
					
				}
	
	}
	if(power)
	{
			
			ironManCordinateFire+=130;
			if(ironManCordinateFire >= vX)
				{
					power = false;
					BallShow = false ;
					vX =screenWidth;
					ironManCordinateFire=0;

					score=score+10;
					SCORE=score;
			
				}
			
	}
	if(fly)
	{		
		if(flyUp)
		{
			ironManCordinatefly+=10;
			if(ironManCordinatefly >= FLYLIIMIT)
				{
						ironManCordinatefly = FLYLIIMIT;					
				}
		}
	}
	if (flyDown)	
			{
			ironManCordinatefly -= 10;
				if(ironManCordinatefly < 40)
				{
					fly = false;
					ironManCordinateY = 0;
				}
			}
	if (jump)
	{
		if(jumpUp)
		{
			ironManCordinateJump += 5;
			if(ironManCordinateJump >= JUMPLIMIT)
			{
				jumpUp = false;
				fly = false;
			}


		}
	
		else
		{
			ironManCordinateJump -= 5;
			if(ironManCordinateJump < 0)
			{
				jump = false;
				ironManCordinateJump = 0;

			}
		}
	

	}
	
}

void change2()
{
	if(vX==screenWidth)
		{
			vX=1100;
			vY=50;
			turnF=true;
			turnB=false;
		}
		else if(vX==800)
		{
			turnF=false;
			turnB=true;
		}

		if(turn)
		{
			if(turnF)
			{
			 vX -=20;
			 vY+=8;
			}
			else if(turnB)
			{
				vX+=20;
				vY-=8;
			}
		}
		
		if(vX <= 0)
		{
			vX = screenWidth + rand()%20;
		}
		BallIndex++;
		if(BallIndex >= 6)
		{
		BallIndex = 0;
		}

}

void change3()
{
	
	
}

void setEnemyVariables()
{
		vX = screenWidth;
		vY = 30 ;
		BallIndex = rand()%30;
		BallShow = true;
		
	
}

int main()
{
	setEnemyVariables();
	iSetTimer(100,change1);
	iSetTimer(100,change2);
	iSetTimer(550,UBackgroundRendering);
	iSetTimer(50,ironManMovement);
	music();
	iInitialize(screenWidth,screenHeight,"CharRend");
	

    return 0;
}
