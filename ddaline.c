#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int xx1,xx2,yy1,yy2;


int sign(int x)
{
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}
void drawline(int X1,int Y1, int X2,int Y2)	
{
	float x,y,dx,dy,length;
	int i;
	
	dx=abs(X2-X1);
	dy=abs(Y2-Y1);
	if(dx>=dy)
		length=dx;
	else
		length=dy;
	dx=(X2-X1)/length;
	dy=(Y2-Y1)/length;
	x=X1 + 0.5*sign(X1);
	y=Y1 + 0.5*sign(Y1);
	i=1;
	while(i<=length)
	{
	
               //  glColor3f(1.0,0.0,0.0);
	         glBegin(GL_POINTS);
	         glVertex2i(x,y);
                 glEnd();
                 glFlush();
		x=x+dx;
		y=y+dy;
		i=i+1;
	}
	glFlush();

}
   

void display(void)                               // for geometric quadrant system ...lines 
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	drawline(xx1,yy1,xx1,yy2);
	drawline(xx1,yy2,xx2,yy2);
	drawline(xx2,yy2,xx2,yy1);
	drawline(xx2,yy1,xx1,yy1);
 glColor3f(0.0,1.0,0.0);
	drawline(xx1,(yy1+yy2)/2,(xx1+xx2)/2,yy2);
	drawline((xx1+xx2)/2,yy2,xx2,(yy1+yy2)/2);
	drawline(xx2,(yy1+yy2)/2,(xx1+xx2)/2,yy1);
	drawline((xx1+xx2)/2,yy1,xx1,(yy1+yy2)/2);	
 glColor3f(0.0,0.0,1.0);
	drawline((xx1+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2,(xx2+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2);
	drawline((xx2+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2,(xx2+(xx1+xx2)/2)/2,(yy1+(yy1+yy2)/2)/2);
	drawline((xx2+(xx1+xx2)/2)/2,(yy1+(yy1+yy2)/2)/2,(xx1+(xx1+xx2)/2)/2, (yy1+(yy1+yy2)/2)/2);
	drawline((xx1+(xx1+xx2)/2)/2, (yy1+(yy1+yy2)/2)/2,(xx1+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2);	

}
void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-600.0,600.0,-600.0,600.0);
        glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc,char** argv)
{
	
    	printf("\n Enter vertex 1 ");
        scanf("%d%d",&xx1,&yy1);
        printf("\n Enter vertex 1 ");
        scanf("%d%d",&xx2,&yy2);
            
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("DDA Line");
	init();
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(display);
	glFlush();
	glutMainLoop();

	return 0;
	
}

