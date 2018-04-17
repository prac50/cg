  #include<stdio.h>  
  #include<GL/glut.h>  
  #include<math.h>  
  int r;
 
int sign(int x)
{
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}

 void putpixel(int x,int y)  
  {  
       glBegin(GL_POINTS);  
       glVertex2i(x,y);  
       glEnd();  
       glFlush();  
  }  
 
  void Bresenham_circle(int r)  
  {  
        int x=0,y=r;
	int d=3-2*r;
        do{  
        putpixel(x, y);                   
        putpixel(y, x);  
        putpixel(-x, y);  
        putpixel(-x, -y);  
        putpixel(-y, x);  
        putpixel(-y, -x);  
        putpixel(y, -x);  
        putpixel(x, -y);  
            if(d<0)  
                 d=d+(4*x)+6;  
            else{  
                 d=d+(4*(x-y))+10;  
                 y--;  
            }  
            x++;  
       } while(x<=y);
  }  


void bresenhamAlg(int X1,int Y1, int X2,int Y2)	
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
	
              
	         glBegin(GL_POINTS);
	         glVertex2i(x,y);
	         glEnd();
                 glFlush();
		x=x+dx;
		y=y+dy;
		i=i+1;
	}
	
}

 
 void triangle ()
 {
	
	bresenhamAlg (0, r, (-1*sqrt(3)*r)/2,-r/2); 
        bresenhamAlg (0, r, (1*sqrt(3)*r)/2,-r/2); 
        bresenhamAlg ((-1*sqrt(3)*r)/2,-r/2,(1*sqrt(3)*r)/2,-r/2); 
	
 }
 void display()  
  {  
        glClearColor(0.0,0.0,0.0,0.0);  
         glColor3f(0.0,1.0,0.0); 
        glClear(GL_COLOR_BUFFER_BIT);  
        Bresenham_circle(r); 
        triangle();
	Bresenham_circle(r/2); 
	
        glFlush();  
  }  
  

 void myinit()  
  {  
        glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-600.0,600.0,-600.0,600.0);
        glClear(GL_COLOR_BUFFER_BIT);  
  } 
  int main(int argc,char** argv)  
  {  
	printf("\nenter radius of circle");
	scanf("%d",&r);       
	glutInit(&argc,argv);  
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
        glutInitWindowSize(800,800);  
        glutCreateWindow("Bresenham-Circle"); 
         myinit();
	glutDisplayFunc(display);  
        glutMainLoop();  
        return 0;  
  }  

