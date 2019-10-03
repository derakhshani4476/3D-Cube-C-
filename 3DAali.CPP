
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#define Pi 3.14159265

double p[8][3]= {{30,-30,-30},{30,30,-30},{30,-30,30},{30,30,30},{-30,-30,-30},{-30,30,-30},{-30,-30,30},{-30,30,30}};
double w[8][3]=  {{30,-30,-30},{30,30,-30},{30,-30,30},{30,30,30},{-30,-30,-30},{-30,30,-30},{-30,-30,30},{-30,30,30}};
double l[12][2]= {{0,1},{0,2},{0,4},{1,3},{1,5},{2,3},{2,6},{3,7},{4,5},{4,6},{5,7},{6,7}};
int xcm=320,ycm=240,t;
double a=0,b=0,d=0,e;//e=sum,t=funckey
float s=1;
int y=0,x=0;
char c;
double m[3][3]= {{1,0,0},{0,cos(a),-sin(a)},{0,sin(a),cos(a)}};  //m= x rotation
double h[3][3]= {{cos(b),0,sin(b)},{0,1,0},{-sin(b),0,cos(b)}};  //n=y //
double n[3][3]= {{cos(d),-sin(d),0},{sin(d),cos(d),0},{0,0,1}};  //l=z //
double ryy[8][3];
void init(){
for (int r=0;r<12;r++)
line((w[l[r][0]][0]*s)+xcm+x,((w[l[r][0]][1])*s)+ycm+y,(w[l[r][1]][0]*s)+xcm+x,(w[l[r][1]][1]*s)+ycm+y);
}
int FUNCKEY (char &c)
{
	c = getch();
	if (c==0) {c=getch();return 0; }
	else return 1 ;
}
void  move(int t,char c){

	switch (c){

			   case 'H':  if (y>-480)
				  y=y-1 ;
				  break;
			   case 'P':  if (y<480)
				  y=y+1;
				  break;
			   case 'M': if (x<320)
				  x=x+1 ;
				  break;

			   case 'K': if (x>-320)
				  x=x-1 ;
				  break;
			}


}
void docommand()
{


	for (int F=0;F<12;F++)
	line((w[l[F][0]][0]*s)+xcm+x,((w[l[F][0]][1])*s)+ycm+y,((w[l[F][1]][0])*s)+xcm+x,((w[l[F][1]][1])*s)+ycm+y);

	t=FUNCKEY(c);
	cleardevice();
	if(t==0)
		move(t,c);
	else{
	switch(c) {

		case 'S' :
		 s=s*2;
		 break;

		case 's':
		 s=s/2 ;
		 break;

		case 'x':
		 a=a+ Pi/50;
		 m[1][1]=cos(a);
		 m[1][2]=-sin(a);
		 m[2][1]=sin(a);
		 m[2][2]=cos(a);
		 break;


		case 'X':
		 a=a-Pi/50;
		 m[1][1]=cos(a);
		 m[1][2]=-sin(a);
		 m[2][1]=sin(a);
		 m[2][2]=cos(a);
		 break;

		case 'y':
		 b=b+Pi/50;
		 h[0][0]=cos(b);
		 h[0][2]=sin(b);
		 h[2][0]=-sin(b);
		 h[2][2]=cos(b);
		 break;

		case 'Y':
		 b=b-Pi/50;
		 h[0][0]=cos(b);
		 h[0][2]=sin(b);
		 h[2][0]=-sin(b);
		 h[2][2]=cos(b);
		 break;

		case 'z':
			d=d+Pi/50;
			n[0][0]=cos(d);
			n[0][1]=-sin(d);
			n[1][0]=sin(d);
			n[1][1]=cos(d);
		 break;

		case'Z':
		 d=d-Pi/50;
			n[0][0]=cos(d);
			n[0][1]=-sin(d);
			n[1][0]=sin(d);
			n[1][1]=cos(d);
		 break;

		       }

	  }

	   for (int g=0;g<8;g++){
			for (int j=0;j<3;j++){
				e=0;
				for(int q=0;q<3;q++)
				{
					e=p[g][q]*m[q][j]+e;
					w[g][j]=e;
				}
			}

	  }


	   for (int S=0;S<8;S++){
			for (int C=0;C<3;C++){
				e=0;
				for(int N=0;N<3;N++)
				{
					e=w[S][N]*h[N][C]+e;
					ryy[S][C]=e;
				}
			}

		}

	   for (int v=0;v<8;v++){
			for (int O=0;O<3;O++){
				e=0;
				for(int Z=0;Z<3;Z++)
				{
					e=ryy[v][Z]*n[Z][O]+e;
					w[v][O]=e;
				}

				}
		}


}
void main()
{

int gd =DETECT;
int gm;
initgraph(&gd,&gm,"");
setcolor(20);
init();
while(c!=27||t!=1){
docommand();
}
closegraph();
}

